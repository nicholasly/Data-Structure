#include <iostream>
#include "LinkedList.h"
using namespace std;

template <class T>
List<T>::List(List<T>& L) {
//  Copy Constructor
	T value;
	LinkNode<T> * srcptr = L.getHead();
//  The address of additional head node
	LinkNode<T> * destptr = first = new LinkNode<T>;
	while (srcptr->link != NULL) {
		value = srcptr->link->data;
		destptr->link = new LinkNode<T>(value);
		destptr = destptr->link;
		srcptr = srcptr->link;
	}
	destptr->link = NULL;
}

template <class T>
void List<T>::makeEmpty() {
	LinkNode<T> * q;
	while(first->link != NULL) {
		q = first->link;
		first->link = q->link;
		delete q;
	}
}

template <class T>
int List<T>::Length() const {
	LinkNode<T> * p = first->link;
	int count = 0;
	while(p != NULL) {
		p = p->link;
		count++;
	}
	return count;
}

template <class T>
LinkNode<T> * List<T>::Search(T x) {
	LinkNode<T> * current = first->link;
	while (current != NULL) {
		if (current->data == x) break;
		else current = current->link;
	}
	return current;
}

template <class T>
LinkNode<T> * List<T>::Locate(int i) {
	if (i < 0) return NULL;
	LinkNode<T> * current = first;
	int k = 0;
	while (current != NULL && k < i) {
		current = current->link;
		k++;
	}
	return current;
}

template <class T>
bool List<T>::getData(int i, T& x) const {
	if (i <= 0) return NULL;
	LinkNode<T> * current = Locate(i);
	if (current == NULL) {
		return false;
	} else {
		x = current->data;
		return true;
	}
}

template <class T>
void List<T>::setData(int i, T& x) {
	if (i <= 0) return;
	LinkNode<T> * current = Locate(i);
	if (current == NULL) return;
	else current->data = x;
}

template <class T>
bool List<T>::Insert(int i, T& x) {
	LinkNode<T> * current = Locate(i);
	if (current == NULL) return false;
	LinkNode<T> * newNode = new LinkNode<T>(x);
	if (newNode == NULL) {
		cerr << "Error!" << endl; exit(1);
	}
	newNode->link = current->link;
	current->link = newNode;
	return true;
}

template <class T>
bool List<T>::Remove(int i, T& x) {
	LinkNode<T> * current = Locate(i - 1);
	if (current == NULL || current->link == NULL) return false;
	LinkNode<T> * del = current->link;
	current->link = del->link;
	x = del->data;
	delete del;
	return true; 
}

template <class T>
void List<T>::output() {
	LinkNode<T> * current = first->link;
	while (current != NULL) {
		cout << current->data << endl;
		current = current->link;
	}
}

template <class T>
List<T>& List<T>::operator=(List<T>& L) {
	T value;
	LinkNode<T> * srcptr = L.getHead();
	LinkNode<T> * destptr = first = new LinkNode<T>;
	while (srcptr->link != NULL) {
		value = srcptr->link->data;
		destptr->link = new LinkNode<T>(value);
		destptr = destptr->link;
		srcptr = srcptr->link;
	}
	destptr->link = NULL;
	return *this;
}
