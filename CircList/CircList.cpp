#include <iostream>
#include "CircList.h"
using namespace std;

template <class T>
CircList::CircList(const T& x) {
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
CircList::~CircList() {
	CircLinkNode<T> * q;
	while (first->link != first || first->link != NULL) {
		q = first->link;
		first->link = q->link;
		delete q;
	}
}

template <class T>
int CircList::CircListLength() const {
	int length = 0;
	CircLinkNode<T> * temp = first->link;
	while (temp != first) {
		temp = temp->link;
		length++;
	}
	return length;
}
template <class T>
CircLinkNode<T> * CircList::getHead() const {
	return first;
}

template <class T>
void CircList::setHead(CircLinkNode<T> * p) {
	first = p;
}

template <class T>
CircLinkNode<T> * CircList::Search(T x) {
	CircLinkNode<T> * temp = first->link;
	while (temp != first) {
		if (x == temp->data) break;
		else temp = temp->link;
	}
	return temp;
}

template <class T>
CircLinkNode<T> * CircList::Locate(int i) {
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
T& CircList::getData(int i) const {
	if (i <= 0 || i > CircListLength()) return; 
	CircLinkNode<T> * current = Locate(i);
	return current->data;
}

template <class T>
void CircList::setData(int i, T& x) {
	if (i <= 0 || i > CircListLength()) return;
	CircLinkNode<T> * current = Locate(i);
	current->data = x;
}

template <class T>
bool CircList::Insert(int i, T& x) {
	CircLinkNode<T> * current = Locate(i);
	if (current == NULL) return false;
	CircLinkNode<T> * newNode<T>(x);
	if (newNode == NULL) {
		cerr << "Error!" << endl; exit(1);
	}
	newNode->link = current->link;
	current->link = newNode;
	return true;
}

template <class T>
bool CircList::Remove(int i, T& x) {
	CircLinkNode<T> * current = Locate(i - 1);
	if (current == NULL || current->link == NULL) return false;
	CircLinkNode<T> * del = current->link;
	current->link = del->link;
	x = del->data;
	delete del;
	return true; 
}
