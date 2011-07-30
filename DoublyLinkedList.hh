#ifndef DOUBLE_LINKED_LIST_HH
#define DOUBLE_LINKED_LIST_HH 1

#include <iostream>

#include <Node.hh>

const int EMPTY_LIST = 1;

template <class T>
class DoublyLinkedList
{
public:
	DoublyLinkedList() {};
	~DoublyLinkedList();
	
	bool isEmpty();
	
	void addToHead(const T);
	void addToTail(const T);
	
	T deleteFromHead();
	T deleteFromTail();
	
	void deleteNode(T);
	
	void addSorted(T);
	
	bool exists(T) const;
	
	bool contains(T) const;

	void printList();
	
private:
	Node<T> *head;
	Node<T> *tail;
};

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	for(Node<T> *n; !isEmpty();)
	{
		n = head->next;
		delete head;
		head = n;
	}
}

template <class T>
void DoublyLinkedList<T>::addToHead(const T obj)
{
	if(head != NULL)
	{
		head = new Node<T>(obj, head);
		head->next->prev = head;
	}
	else head = tail = new Node<T>(obj);
}

template <class T>
void DoublyLinkedList<T>::addToTail(const T obj)
{
	if(tail != NULL)
	{
		tail = new Node<T>(obj, NULL, tail);
		tail->prev->next = tail;
	}
	else head = tail = new Node<T>(obj);
}

template <class T>
T DoublyLinkedList<T>::deleteFromHead()
{
	if(head != NULL)
	{
		T obj = head->info;
		if(head == tail)
		{
			delete head;
			head = tail = NULL;
		}
		else
		{
			head = head->next;
			delete head->prev;
			head->prev = NULL;
		}
		return obj;
	}
	else throw (EMPTY_LIST);
}

template <class T>
T DoublyLinkedList<T>::deleteFromTail()
{
	if(head != NULL)
	{
		T obj = tail->info;
		if(head == tail)
		{
			delete tail;
			head = tail = NULL;
		}
		else
		{
			tail = tail->prev;
			delete tail->next;
			tail->next = NULL;
		}	
		return obj;
	}
	else throw (EMPTY_LIST);
}

template <class T>
void DoublyLinkedList<T>::deleteNode(T obj)
{
	if(head != NULL)
	{
		if(head == tail && obj == head ->info)
		{
			delete head;
			head = tail = NULL;
		}
		else if(obj == head->info)
		{
			Node<T> *tmp = head;
			head = head->next;
			delete tmp;
		}
		else
		{
			Node<T> *pred, *tmp;
			for(pred = head, tmp=head->next;
				tmp != NULL && tmp->info != obj;
				pred = pred->next, tmp = tmp->next);
			if(tmp != NULL)
			{
				pred->next = tmp->next;
				if(tmp == tail) 
					tail = pred;
				delete tmp;
			}
		}
	}
}

template <class T>
void DoublyLinkedList<T>::addSorted(T obj)
{
	if(head != NULL)
	{
		if(obj <= head->info) {addToHead(obj);}
		else if(obj >= tail->info) {addToTail(obj);}
		else 
		{
			Node<T> *tmp;
			tmp = head;
			while(obj >= tmp->info)
			{
				tmp = tmp->next;
			}
			tmp = new Node<T>(obj, tmp, tmp->prev);
			tmp->next->prev = tmp;
			tmp->prev->next = tmp;
		}
	}
	else head = tail = new Node<T>(obj);
}

template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
	return (head == NULL);
}

template <class T>
void DoublyLinkedList<T>::printList()//Print list element by element
{
	Node<T> *tmp;
	tmp = head;
	while( tmp!=NULL )
	{
		std::cout << tmp->info << " ";
		tmp = tmp->next;
	}
}


template <class T>
bool DoublyLinkedList<T>::contains(T obj) const
{
	Node<T> *node;
	for(node = head;node!=NULL && node->info != obj;node=node->next);
	return (node != NULL);
}

#endif // DOUBLE_LINKED_LIST_HH
