#include <iostream>

using namespace std;

template<typename KeyT, typename T>
class Tree {
	struct Node {
		KeyT	 key;
        T        data;
		Node	*left, *right, *parent;

        Node(KeyT key_, const T &data_) : key(key_), data(data_), left(nullptr), right(nullptr), parent(nullptr) {}

		template<typename ArgT>
        bool Walk(bool (*callback)(T &elm, ArgT arg, KeyT key), ArgT arg) {
			if (this == nullptr)
				return false;
            if (left->template Walk<ArgT>(callback, arg))
				return true;
            if (callback(data, arg, key))
				return true;

//            Node node;
//            node.key = 123;
//            Node *foo = &node;
//            Node **moo = &foo;
//            foo->key = 123;     // запишется в поле key объекта node
//            (*foo).key = 123;           // *foo.key  ===   *(foo.key)
            return right->template Walk<ArgT>(callback, arg);
		}
	};

    Node    *root;
	
    void SwapNodesSimple(Node *node1, Node *node2) {
        KeyT tmpKey = node1->key;
        T tmpData = node1->data;
        node1->key = node2->key;
        node1->data = node2->data;
        node2->key = tmpKey;
        node2->data = tmpData;
    }

    void SwapNodes(Node *node1, Node *node2) {
		Node *parent1 = node1->parent;
		Node *lchild1 = node1->left, *rchild1 = node1->right;
		
		node1->parent = node2->parent;
		node1->left = node2->left;
		node1->right = node2->right;
        if (node2->parent != nullptr) {
			if (node2->parent->left == node2) {
				node2->parent->left = node1;
			} else {
				node2->parent->right = node1;
			}
		}
        if (node2->left != nullptr) {
            node2->left->parent = node1;
        }
        if (node2->right != nullptr) {
            node2->right->parent = node1;
        }
		
		node2->parent = parent1;
		node2->left = lchild1;
		node2->right = rchild1;
		if (parent1 != nullptr) {
			if (parent1->left == node1) {
				parent1->left = node2;
			} else {
				parent1->right = node2;
			}
        }
        if (node1->left != nullptr) {
            node1->left->parent = node2;
        }
        if (node1->right != nullptr) {
            node1->right->parent = node2;
        }
	}

    void SmallTurnLeft(Node *upper, Node *lower) {
        lower -> parent = upper -> parent;
        lower -> left = upper;
        upper -> parent = lower;
        if(lower -> parent != nullptr){
            if(lower ->parent ->left == upper ) {lower ->parent ->left = lower;}
            else {lower ->parent -> right = lower;}
        }
    }

public:
    class iterator {
        Node *node;
        iterator(Node *n) : node(n) {}
        friend class Tree;
    public:
        T& operator *() { return node->data; }
        iterator& operator ++() {        // ++a  lvalue
            if (node->right) {
                node = node->right;
                while (node->left)
                    node = node->left;
            } else {
                while (node->parent && node->parent->right == node)
                    node = node->parent;
                node = node->parent;
            }
        }
        iterator operator ++(int) {      // a++  rvalue
            iterator prev = *this;
            ++(*this);
            return prev;
        }
        iterator& operator --()    { /* TODO */ }
        iterator  operator --(int) { /* TODO */ }
    };

    class reverse_iterator {
        // TODO 1: Написать аналог iterator, работающий в обратном направлении.
        // TODO 2: Вынести общий код iterator и reverse_iterator в базовый класс.
    };

    iterator begin() {
        if (root == nullptr)
            return end();
        auto node = root;
        while (node->left)
            node = node->left;
        return iterator(node);
    }
    iterator end() { return iterator(nullptr); }
    reverse_iterator rbegin() { /* TODO */ }
    reverse_iterator rend() { /* TODO */ }

    Tree() : root(nullptr) {}

    iterator Find(KeyT what) const {
		for (Node *node = root; node != nullptr;) {
            if (node->key == what) {
                return iterator(node);
			} else if (what > node->key) {
				node = node->right;
			} else {
				node = node->left;
			}
		}
        return iterator(nullptr);
	}
	
	bool Insert(KeyT key, const T &elm) {
		if (root == nullptr) {
			root = new Node(key, elm);
			return true;
		}
		Node *last = nullptr;
		for (Node *node = root; node != nullptr;) {
			last = node;
            if (node->key == key) {
				return false;
			} else if (key > node->key) {
				node = node->right;
			} else {
				node = node->left;
			}
		}
		// попадаем сюда, если указанный ключ отсутствует в дереве; last != nullptr
		Node *newNode = new Node(key, elm);
		newNode->parent = last;
		if (key > last->key)
			last->right = newNode;
		else
			last->left = newNode;
		return true;
	}

    void Remove(iterator iter) {
        Node *node = iter->node;
repeat_delete:
        // удаляем; last != nullptr
        if (node->left == nullptr && node->right == nullptr) {
            // тривиальный случай, удаляем лист
            if (node->parent->left == node)
                node->parent->left = nullptr;
            else
                node->parent->right = nullptr;
            delete node;
        } else if (node->left != nullptr) {
            // подтягиваем крайний правый элемент из левого поддерева
            Node *switch_node;
            for (switch_node = node->left; switch_node->right != nullptr;
                 switch_node = switch_node->right);
            SwapNodes(switch_node, node);
            goto repeat_delete;
        } else /*if (node->right != nullptr)*/ {
            // подтягиваем крайний левый элемент из правого поддерева
            Node *switch_node;
            for (switch_node = node->right; switch_node->left != nullptr;
                 switch_node = switch_node->left);
            SwapNodes(switch_node, node);
            goto repeat_delete;
        }
    }

    bool Remove(KeyT key) {
        if (root == nullptr)
			return false;
		Node *last = nullptr;
		for (Node *node = root; node != nullptr;) {
			last = node;
			if (node->key == key) {
                Remove(iterator(node));
				return true;
			} else if (key > node->key) {
				node = node->right;
			} else {
				node = node->left;
			}
		}
		return false;
	}

	// Обход дерева
    template<typename ArgT>
    void Walk(bool (*callback)(T &elm, ArgT arg, KeyT key), ArgT arg) {
		root->template Walk<ArgT>(callback, arg);
	}
};

bool PrintNodeToFile(std::string &data, std::ostream &outputFile, int key) {
    outputFile << "Node: " << data << " " << key << std::endl;
	if (data == "No more")
		return true;
	return false;
}

/*

bool WriteToFile(const char *filename, const char *str) {
	FILE *f;
	// выделение промежуточных ресурсов
	
	if ((f = fopen(filename, "w")) == NULL)
		goto err;
	
	if (!fputs(str, f))
		goto err;
	
	if (!fflush(f))
		goto err;
	
	if (!fclose(f))
		goto err;
	
	std::unique_ptr
	
	return true;

err:
	// обработать ошибку, освободить ресурсы
	return false;
}
*/

#include <forward_list>
#include <list>
#include <vector>

int main() {
	Tree<int, std::string> tree;
	tree.Insert(234, "Moo");
	tree.Insert(123, "Foo");
    tree.Insert(345, "Bleah");
    tree.Insert(893, "Moah");
    tree.Insert(043, "CooKoo");
    std::cout << "Printing tree:" << std::endl;
	tree.Walk<std::ostream&>(PrintNodeToFile, std::cout);

    cout << "Vector:" << endl;
    std::vector<int> myvector { 121, 443, 565, 323 };
    for (size_t i = 0; i != myvector.size(); i++) {
        cout << myvector[i] << endl;
    }
    for (auto it = myvector.begin(); it != myvector.end(); it++) {
        cout << *it << endl;
    }

    cout << "List:" << endl;
    std::list<int> mylist { 121, 443, 565, 323 };
    for (auto it = mylist.begin(); it != mylist.end(); it++) {
        cout << *it << endl;
    }

    cout << "Forward list:" << endl;
    std::list<int> myflist { 121, 443, 565, 323 };
    for (auto it = myflist.begin(); it != myflist.end(); it++) {
        cout << *it << endl;
    }



	return 0;
}
