#ifndef EXAM_LIST_H
#define EXAM_LIST_H

template<typename T>
class ForwardList {
	struct Node {
		T data;
		Node *next;

		Node(const T &e) : data(e), next(nullptr) {}
	};

	Node *head;

public:
	ForwardList() : head(nullptr) {}
};

template<typename T>
class BackwardList {
	struct Node {
		T data;
		Node *prev;

		Node(const T &e) : data(e), prev(nullptr) {}
	};

	Node *tail;

public:
	BackwardList() : tail(nullptr) {}
};

template<typename T>
class List {
	struct Node {
		T data;
		Node *next, *prev;

		Node(const T &e) : data(e), next(nullptr), prev(nullptr) {}
	};

	Node *head, tail;

public:
	List() : head(nullptr), tail(nullptr) {}
};

#endif
