#include <iostream>
#include "SeqQueue.h"
template <class T>
SeqQueue<T>::SeqQueue(int sz) : front(0), rear(0), maxSize(sz)  {
	elements = new T[maxSize];
	assert(elements != NULL);
}

template <class T>
bool SeqQueue<T>::EnQueue(const T& x) {
	if (IsFull()) return false;
	elements[rear] = x;
	rear = (rear + 1) % maxSize;
	return true;
}

template <class T>
bool SeqQueue<T>::DeQueue(T& x) {
	if (IsFull()) return false;
	x = elements[front];
	front = (front + 1) % maxSize;
	return true;
}

template <class T>
bool SeqQueue<T>::getFront(T& x) {
	if (IsEmpty()) return false;
	x = elements[front];
	return true;
}

template <class T>
std::ostream& operator << (std::ostream& os, SeqQueue<T>& Q) {
	os << "front =" << Q.front << ", rear =" << Q.rear << std::endl;
	for (int i = Q.front; i != Q.rear; i = (i + 1) % Q.maxSize) {
		os << i << ":" << Q.elements[i] << std::endl;
	}
	return os;
}
