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

	void pop_front() {
		if (size > 0) {
			shared_ptr<SingleNode<T>> temp = this->head;
			head = head->next;
			temp.reset();
			size--;
		}
	}


	void pop_back() {
		if (size > 0) {
			if (size == 1) {
				tail.reset();
				head.reset();
				size--;
				return;
			}
			shared_ptr<SingleNode<T>> temp = this->head;
			while (temp->next != tail) {
				temp = temp->next;
			}

			tail.reset();
			temp->next.reset();
			tail = temp;
			size--;
		}
	}

	size_t length() const {
		return this->size;
	}

	bool empty() const {
		return size == 0;
	}

	T& operator[](const size_t index) {
		if (index >= size || index < 0) {
			throw runtime_error("Out of range list");
		}
		shared_ptr<SingleNode<T>> temp = this->head;
		for (int i = 0; i != index; i++, temp = temp->next);
		return temp->value;
	}

	int find(const T& value) const {
		shared_ptr<SingleNode<T>> temp = this->head;
		int index = 0;

		while (temp) {
			if (temp->value == value) return index;
			index++;
			temp = temp->next;
		}
		
		return -1;
	}

	void insertAt(const size_t index, const T& value) {
		if (index >= size || index < 0) {
			throw runtime_error("Out of range list");
		}

		if (index == 0) {
			push_front(value);
			return;
		}

		if (index == size - 1) {
			push_back(value);
			return;
		}
		shared_ptr<SingleNode<T>> temp = this->head;

		for (int i = 0; i != index-1; i++, temp = temp->next);

		shared_ptr<SingleNode<T>> newNode = make_shared<SingleNode<T>>(value);
		
		newNode->next = temp->next;
		temp->next = newNode;
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