#include <iostream>

using namespace std;

template<typename KeyT, typename T>
class Tree {
	struct Node {
		KeyT	 key;
		T	 data;
		Node	*left, *right, *parent;

		Node(KeyT key_, const T &data_) : key(key_), data(data_), left(nullptr), right(nullptr), parent(nullptr) {}

		template<typename ArgT>
		bool Walk(bool (*callback)(T &elm, ArgT arg), ArgT arg) {
			if (this == nullptr)
				return false;
			if (left->template Walk<ArgT>(callback, arg))
				return true;
			if (callback(data, arg))
				return true;
			return right->template Walk<ArgT>(callback, arg);
		}
	};

	Node*	root;
	
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
	}
	
public:
	Tree() : root(nullptr) {}

	bool Find(KeyT what, T &result) const {
		for (Node *node = root; node != nullptr;) {
			if (node->key == what) {
				result = node->data;
				return true;
			} else if (what > node->key) {
				node = node->right;
			} else {
				node = node->left;
			}
		}
		return false;
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

	bool Remove(KeyT key) {
		if (root == nullptr)
			return false;
		Node *last = nullptr;
		for (Node *node = root; node != nullptr;) {
			last = node;
			if (node->key == key) {
repeat_delete:
				// удаляем; last != nullptr
				if (node->left == nullptr && node->right == nullptr) {
					// тривиальный случай, удаляем лист
					if (last->left == node)
						last->left = nullptr;
					else
						last->right = nullptr;
					delete node;
					return true;
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
	void Walk(bool (*callback)(T &elm, ArgT arg), ArgT arg) {
		root->template Walk<ArgT>(callback, arg);
	}
};

bool PrintNodeToFile(std::string &data, std::ostream &outputFile) {
	outputFile << "Node: " << data << std::endl;
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


int main() {
	Tree<int, std::string> tree;
	tree.Insert(234, "Moo");
	tree.Insert(123, "Foo");
	std::cout << "Printing tree:" << std::endl;
	tree.Walk<std::ostream&>(PrintNodeToFile, std::cout);

	return 0;
}
