#include <memory>

using namespace std;
template<typename T>
struct SingleNode {
	T value;
	shared_ptr<SingleNode<T>> next;

	SingleNode(const T& value) : value{ value }, next{ nullptr } {}
};