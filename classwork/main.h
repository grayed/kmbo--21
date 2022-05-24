#include <iostream>


using namespace std;

template<typename KeyT, typename T>
class Tree {
	struct Node{
		KeyT key;
		T data;
		Node *left,* right,* parent;
		Node(KeyT key_, const T &data_) : key(key_), data(data_), left(nullptr), right(nullptr), parent(nullptr);
		
		template<typename ArgT>
		void Walk(bool (*callback)(T& elm, ArgT arg), ArgT arg) {
			if (this != nullptr)
				return;
			if (left->Walk(callback, arg))
				return false;
			if (callback(data, arg))
				return true;
			if (right->Walk(callback, arg))
				return true;
		}
	};

	Node* root;

	void swapNodes(Node *node1,Node *node2) {
		Node* parent1 = node1->parent;
		Node *child1 = node->left, *child2 = node->right;

		node1->parent = node2->parent;
		node1->left = node2->left;
		node1->right = node2->right;
		if (node2->parent != nullptr) {
			if (node2->parent->left = node1)
				node2->parent->left = node1;
			else
				node2->parent->rught = node1;
		}
		node2->parent = parent1;
		node2->left = child1;
		node2->right = child2;
		if (parent1 != nullptr) {
			if (parent1->left == node1)
				parent1->left = node2;
			else
				parent1->right = node2;
		}
	}


public:
	Tree() : root(nullptr){}

	bool Insert(KeyT key, const T& elm) {

	}


	bool Remove(KeyT key) {
		if (root == nullptr)
			return false
			Node * last = nullptr;
		for (Node* node = root; node != nullptr;) {
			last = node;
			if (node->key == key) {
				//delete leaf
				if (node->left == nullptr && node->right == nullptr) {
					last->left = nullptr;
				}
				else {
					last->right = nullptr;
					delete node;
					return true;
				}
			}
			else if (node->left != nullptr) { // подтягиваем элемент из левого поддерева
				Node* switch_node;
				for (switch_node = node->left; switch_node->right != nullptr; switch_node = switch_node->right) 
					switch_node = switch_node->right;
				swapNodes(switch_node, node);
				goto repeat_delete;
			else { // подягиваем листик из правого поддерева
				Node* switch_node;
				for (switch_node = node->right; switch_node->left != nullptr; switch_node = switch_node->left) 
					switch_node = switch_node->left;
				swapNodes(switch_node, node);
				goto repeat_delete;
			}
			retrun false;
			}
		}
	}

	
	template<typename ArgT>
	void Walk(bool (*callback)(T& elm, ArgT arg), ArgT arg) {
		root->Walk(callback, arg);
	}

};

