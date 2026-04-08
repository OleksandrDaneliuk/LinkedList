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

		newNode->next = head;
		head = newNode;

	}

};