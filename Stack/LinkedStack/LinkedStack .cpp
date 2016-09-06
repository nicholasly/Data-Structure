#include <iostream>
#include <assert.h>
#include "LinkedStack.h"

template <class T>
void LinkedStack<T>::Push(T& x) {
	top = new LinkNode<T>(x, top);
	assert(top != NULL);
}

template <class T>
bool LinkedStack<T>::Pop(T& x) {
	if (isEmpty()) return false;
	LinkNode<T> * p = top;
	top = top->link;
	x = p->data;
	delete p;
	return true;
}

template <class T>
bool LinkedStack<T>::getTop(T& x) const {
	if (isEmpty()) return false;
	x = top->data;
	return true;
}

template <class T>
int LinkedStack<T>::getSize() const {
	LinkNode<T> * p = top;
	int k = 0;
	while (p != NULL) {
		p = p->link;
		k++;
	}
	return k;
}

template <class T>
void LinkedStack<T>::makeEmpty() {
	LinkNode<T> * p;
	while (top != NULL) {
		p = top;
		top = top->link;
		delete p;
	}
}

template <class T>
std::ostream& operator << (std::ostream& os, LinkedStack<T>& s) {
	os << "The size is " << s.getSize() << std::endl;
	LinkNode<T> * p = s.top;
	int i = 0;
	while (p != NULL) {
		os << ++i << ":" << p->data << std::endl;
		p = p->link;
	}
	return os;
}
