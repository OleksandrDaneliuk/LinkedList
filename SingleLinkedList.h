#include <memory>
#include <iostream>
#include "SingleNode.h"
using namespace std;
template<typename T>
class SingleLinkedList {
private:
	shared_ptr<SingleNode<T>> head;
	shared_ptr<SingleNode<T>> tail;
	size_t size;
public:
	SingleLinkedList() : size(0) {}

	void push_back(const T& value) {
		shared_ptr<SingleNode<T>> newNode = make_shared<SingleNode<T>>(value);

		if (size == 0) {
			head = newNode;
			tail = head;
			size++;
			return;
		}

		size++;
		tail->next = newNode;
		tail = tail->next;

	}

	void push_front(const T& value) {
		shared_ptr<SingleNode<T>> newNode = make_shared<SingleNode<T>>(value);

		if (size == 0) {
			head = newNode;
			tail = head;
			size++;
			return;
		}

		size++;
		newNode->next = head;
		head = newNode;
	}

	friend std::ostream& operator<<(std::ostream& os, const SingleLinkedList& obj) {
		auto node = obj.head;
		if (obj.size == 0) {
			os << "[]";
			return os;
		}

		os << "[";
		while (node->next) {
			os << node->value << ", ";
			node = node->next;
		}
		os << node->value << "]";
		return os;
	}

};