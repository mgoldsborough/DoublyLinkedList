#ifndef NODE_HH
#define NODE_HH 1

#include <cstddef>

template <class T>
class Node
{
public:
	Node(const T, Node*, Node*);
	Node();
	~Node();
	
private:
	Node* next;
	Node* prev;
	T info;
};

template <class T>
Node<T>::Node(
	const T info, Node* next = NULL, Node* prev = NULL)
{
	this.info = info;
	this.next = next;
	this.prev = prev;
}

template <class T>
Node<T>::Node()
{
	next = prev = NULL;
}

template <class T>
Node<T>::~Node()
{
	return;
}


#endif // NODE_HH
