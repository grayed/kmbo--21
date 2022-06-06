#pragma once

#include <iostream>
#include <vector>
#include <cstddef>
#include <sys/types.h>
#include <iostream>

using namespace std;

template<typename KeyT, typename T>
class Tree {
	struct Node {
		KeyT	 key;
		T        data;
		Node* left, * right, * parent;

		Node(KeyT key_, const T& data_) : key(key_), data(data_), left(nullptr), right(nullptr), parent(nullptr) {}

		template<typename ArgT>
		bool Walk(bool (*callback)(T& elm, ArgT arg, KeyT key), ArgT arg) {
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

	Node* root;

	void SwapNodesSimple(Node* node1, Node* node2) {
		KeyT tmpKey = node1->key;
		T tmpData = node1->data;
		node1->key = node2->key;
		node1->data = node2->data;
		node2->key = tmpKey;
		node2->data = tmpData;
	}

	void SwapNodes(Node* node1, Node* node2) {
		Node* parent1 = node1->parent;
		Node* lchild1 = node1->left, * rchild1 = node1->right;

		node1->parent = node2->parent;
		node1->left = node2->left;
		node1->right = node2->right;
		if (node2->parent != nullptr) {
			if (node2->parent->left == node2) {
				node2->parent->left = node1;
			}
			else {
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
			}
			else {
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

	void SmallTurnLeft(Node* upper, Node* lower) {
		lower->parent = upper->parent;
		lower->left = upper;
		upper->parent = lower;
		if (lower->parent != nullptr) {
			if (lower->parent->left == upper) { lower->parent->left = lower; }
			else { lower->parent->right = lower; }
		}
	}
	class uni_iterator {
		Node* node;
		uni_iterator(Node *n) : node(n){}
		friend class Tree;
	protected:
		uni_iterator& next() {
			if (node->right) {
				node->right;
				while (node->left)
					node->left;
			}
			else {
				while (node->parent && node->parent->right == node)
					node = node->parent;
				node->parent;
			}
		}
		uni_iterator& prev() {
			if (node->left) {
				node = node->left;
				while (node->right)
					node = node->right;
			}
			else {
				while (node->parent && node->parent->left == node)
					node = node->parent;
				node = node->parent;
			}
			return *this;
		}
	};
	class iterator : public uni_iterator{
		Node* node;
		iterator(Node *n) : node(n) {}
		friend class Tree;
	public:
		T& operator *() { return node->data; }
		iterator& operator++() {
			node->next(); return *this;
		}
		iterator operator++(int) { //постфиксный
			auto temp = *this;
			++(*this);
			return temp;
		}
	};
	class reverse_iterator : public uni_iterator {
		Node* node;
		reverse_iterator(Node* n) : node(n) {}
	public:
		T& operator *() { return node->data; }
		iterator& operator--() { 
			node->prev(); return *this
		}
		iterator operator--(int) { 
			auto temp = *this;
			--(*this);
			return temp;
		}
	};
	iterator begin() {
		if (root == nullptr) return end();
		Node* node == root;
		while (node->left)
			node = node->left;
		return iterator(node)
	}
	iterator end() { return iterator(nullptr); }
	reverse_iterator rbegin() {/*todo*/ }
	reverse_iterator rend() { /*to do*/ }

	


public:
	Tree() : root(nullptr) {}

	bool Find(KeyT what, T& result) const {
		for (Node* node = root; node != nullptr;) {
			if (node->key == what) {
				result = node->data;
				return true;
			}
			else if (what > node->key) {
				node = node->right;
			}
			else {
				node = node->left;
			}
		}
		return false;
	}

	bool Insert(KeyT key, const T& elm) {
		if (root == nullptr) {
			root = new Node(key, elm);
			return true;
		}
		Node* last = nullptr;
		for (Node* node = root; node != nullptr;) {
			last = node;
			if (node->key == key) {
				return false;
			}
			else if (key > node->key) {
				node = node->right;
			}
			else {
				node = node->left;
			}
		}
		// попадаем сюда, если указанный ключ отсутствует в дереве; last != nullptr
		Node* newNode = new Node(key, elm);
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
		Node* last = nullptr;
		for (Node* node = root; node != nullptr;) {
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
				}
				else if (node->left != nullptr) {
					// подтягиваем крайний правый элемент из левого поддерева
					Node* switch_node;
					for (switch_node = node->left; switch_node->right != nullptr;
						switch_node = switch_node->right);
					SwapNodes(switch_node, node);
					goto repeat_delete;
				}
				else /*if (node->right != nullptr)*/ {
					// подтягиваем крайний левый элемент из правого поддерева
					Node* switch_node;
					for (switch_node = node->right; switch_node->left != nullptr;
						switch_node = switch_node->left);
					SwapNodes(switch_node, node);
					goto repeat_delete;
				}
				return true;
			}
			else if (key > node->key) {
				node = node->right;
			}
			else {
				node = node->left;
			}
		}
		return false;
	}

	// Обход дерева
	template<typename ArgT>
	void Walk(bool (*callback)(T& elm, ArgT arg, KeyT key), ArgT arg) {
		root->template Walk<ArgT>(callback, arg);
	}
};

bool PrintNodeToFile(std::string& data, std::ostream& outputFile, int key) {
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


//Шаблоннный класс MyVector, операции не определены
template<typename T>
class MyVector {
	T* data;
	size_t size;
public:
	class iterator {
		MyVector* v;
		size_t pos;

		iterator(MyVector* vect, size_t n) : v(vect), pos(n) {}
		friend class MyVector;
	public:
		T operator *() { return (*v)[pos]; }

		iterator& operator++() { //префиксный инкремент
			if (++pos == v->getSize())
				v = nullptr;
			return *this;
		}

		iterator operator++(int) { // постфиксный оператор инкремента
			pos++;
			if (pos == v->getSize())
				v = nullptr;
			return *this;
		}

		iterator operator+(ptrdiff_t offset) const { //проверить что мы не выходим за границы массива
			if (pos + offset > v->getSize())
				v = nullptr;
			pos += offset;
			return *this;
		}
		iterator operator-(ptrdiff_t offset) const {
			offset *= (-1);
			pos += offset;
			return *this;
		}
		operator bool() const {
			if (v != nullptr)
				return true;
			return false;
			}
		};
		iterator begin() {
			if (size == 0) return end();
			return iterator(this, 0);
		}
		iterator end() { return iterator(nullptr, 0); }
		
		size_t getSize() const { return size; }

		const T& operator[] (size_t idx) const { return data[idx]; }
			  T& operator[] (size_t idx)			   { return data[idx]; }

};


