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


};