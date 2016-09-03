#include <iostream>
#include "CircList.h"
using namespace std;

template <class T>
CircList<T>::CircList() {
	last = first = NULL;
}

template <class T>
CircList<T>::CircList(const T& x) {
	last = first = new CircLinkNode<T>(x);
}

template <class T>
CircList<T>::CircList(CircList<T>& L) {
	T value;
	CircLinkNode<T> * srcptr = L.getHead();
	CircLinkNode<T> * destptr = first = new CircLinkNode<T>;
	while (srcptr->link != first) {
		value = srcptr->link->data;
		destptr->link = new CircLinkNode<T>(value);
		destptr = destptr->link;
		srcptr = srcptr->link;
	}
	last = destptr;
	last->link = first;
}

template <class T>
CircList<T>::~CircList() {
	CircLinkNode<T> * q;
	while (first->link != first || first->link != NULL) {
		q = first->link;
		first->link = q->link;
		delete q;
	}
}

template <class T>
int CircList<T>::Length() const {
	int length = 0;
	CircLinkNode<T> * temp = first->link;
	while (temp != first) {
		temp = temp->link;
		length++;
	}
	return length;
}

template <class T>
CircLinkNode<T> * CircList<T>::getHead() const {
	return first;
}

template <class T>
void CircList<T>::setHead(CircLinkNode<T> * p) {
	first = p;
}

template <class T>
CircLinkNode<T> * CircList<T>::Search(T x) {
	CircLinkNode<T> * temp = first->link;
	while (temp != first) {
		if (x == temp->data) break;
		else temp = temp->link;
	}
	return temp;
}

template <class T>
CircLinkNode<T> * CircList<T>::Locate(int i) {
	if (i < 0) return NULL;
	int length = 0;
	CircLinkNode<T> * temp = first;
	while (temp != last && length < i) {
		temp = temp->link;
		length++;
	}
	return temp;
}

template <class T>
T& CircList<T>::getData(int i) const {
	if (i <= 0 || i > Length()) return; 
	CircLinkNode<T> * current = Locate(i);
	return current->data;
}

template <class T>
void CircList<T>::setData(int i, T& x) {
	if (i <= 0 || i > Length()) return;
	CircLinkNode<T> * current = Locate(i);
	current->data = x;
}

template <class T>
bool CircList<T>::Insert(int i, T& x) {
	CircLinkNode<T> * current = Locate(i);
	if (current == NULL) return false;
	CircLinkNode<T> * newNode = new CircLinkNode<T>(x);
	if (newNode == NULL) {
		cerr << "Error!" << endl; exit(1);
	}
	newNode->link = current->link;
	current->link = newNode;
	return true;
}

template <class T>
bool CircList<T>::Remove(int i, T& x) {
	CircLinkNode<T> * current = Locate(i - 1);
	if (current == NULL || current->link == NULL) return false;
	CircLinkNode<T> * del = current->link;
	current->link = del->link;
	x = del->data;
	delete del;
	return true; 
}
