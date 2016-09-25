#include <iostream>
#include "LinkedQueue.h"

template <class T>
void LinkedQueue<T>::makeEmpty() {
	LinkNode<T> * p;
	while (front != NULL) {
		p = front;
		front = front->link;
		delete p;
	}
}

template <class T>
bool LinkedQueue<T>::EnQueue(const T& x) {
	if (front == NULL) {
		front = rear = new LinkNode<T>(x);
		if (front == NULL) return false;
	}
	else {
		rear->link = new LinkNode<T>(x);
		if (rear->link == NULL) return false;
		rear = rear->link;
	}
}

template <class T>
bool LinkedQueue<T>::DeQueue(T& x) {
	if (IsEmpty()) return true;
	LinkNode<T> * p = front;
	x = front->data;
	front = front->link;
	delete p;
	return true;
}

template <class T>
bool LinkedQueue<T>::getFront(T& x) const {
	if (IsEmpty()) return false;
	x = front->data;
	return true;
}

template <class T>
int LinkedQueue<T>::getSize() const {
	LinkNode<T> * p = front;
	int k = 0;
	while (p != NULL) {
		p = p->link;
		k++;
	}
	return k;
}

template <class T>
std::ostream& operator << (std::ostream& os, LinkedQueue<T>& Q) {
	os << "The size of Queue is " << Q.getSize() << std::endl;
	LinkNode<T> * p = Q.front;
	int i = 0;
	while (p != NULL) {
		i++;
		os << i << ":" << p->data << std::endl;
		p = p->link;
	}
	return os;
}
