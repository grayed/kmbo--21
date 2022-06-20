#ifndef EXAM_TREE_H
#define EXAM_TREE_H

#include <iterator>
#include <utility>


template<typename KeyT, typename DataT>
class BinaryTree {
	struct Node {
		Node *left, *right, *parent;
		friend class BinaryTree<KeyT, DataT>;

		Node(KeyT key_, DataT data_, Node *parent_ = nullptr)
			: key(key_)
			, data(data_)
			, left(nullptr)
			, right(nullptr)
			, parent(parent_)
		{}

		Node* next() {
			Node *node = this;
			if (node->right) {
				node = node->right;
				while (node->left)
					node = node->left;
			}
			else {
				while (node->parent && node == node->parent->right)
					node = node->parent;
				if (node->parent)
					node = node->parent;
			}
			return node;
		}

		Node* prev() {
			Node *node = this;
			if (node->left) {
				node = node->left;
				while (node->right)
					node = node->right;
			}
			else {
				while (node->parent && node == node->parent->left)
					node = node->parent;
				if (node->parent)
					node = node->parent;
			}
			return node;
		}
	};

	Node *root;

protected:
	static void DeleteRecursive(Node* node) {
		if (node) {
			DeleteRecursive(node->left);
			DeleteRecursive(node->right);
			delete node;
		}
	}

	class iterator_base : std::iterator<std::bidirectional_iterator_tag, std::pair<KeyT, DataT>> {
		Node* node;

	public:
		operator bool() const {
			return node != nullptr;
		}

	protected:
		iterator_base(Node* node_ = nullptr) : node(node_) {}
	};
public:

	class iterator : iterator_base {
		friend class BinaryTree;
		iterator(Node node_) : iterator_base(node_) {}

	public:
		iterator& operator++() {
			node = node->next();
			return *this;
		}

		iterator operator++(int) {
			auto res = *this;
			++(*this);
			return res;
		}

		iterator& operator--() {
			node = node->prev();
			return *this;
		}

		iterator operator--(int) {
			auto res = *this;
			--(*this);
			return res;
		}
	};

	BinaryTree() : root(nullptr) {}
	virtual ~BinaryTree() {
		DeleteRecursive(root);
	}

	iterator begin() {
		Node *node = root;
		if (node) {
			while (node->left)
				node = node->left;
		}
		return iterator(node);
	}

	iterator end() {
		return iterator();
	}
};

template<typename KeyT, typename DataT>
class SearchTree : public BinaryTree<KeyT, DataT> {
public:

};

#endif
