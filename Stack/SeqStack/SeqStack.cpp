#include <iostream>
#include "SeqStack.h"
template <class T>
SeqStack<T>::SeqStack(int sz) : top(-1), maxSize(sz) {
	elements = new T[maxSize];
	//  create an array
	assert(elements != NULL);
	//  assert: if the distribution of the space is successful
}

template <class T>
void SeqStack<T>::overflowProcess() {
	T * newArray = new T[maxSize + stackIncreament];
	//  create a new array with larger size
	if (newArray == NULL) {
		std::cerr << "Error!" << std::endl; exit(1);
	}
	for (int i = 0; i <= top; i++) {
		newArray[i] = elements[i];
	}
	maxSize += stackIncreament;
	delete []elements;
	elements = newArray;
	//  replace elements[] with newArray[]
}

template <class T>
void SeqStack<T>::Push(const T& x) {
	if (isFull()) overflowProcess();
	elements[++top] = x;
}
//  push a element into the stack

template <class T>
bool SeqStack<T>::Pop(T& x) {
	if (isEmpty()) return false;
	x = elements[top--];
	return true;
}
//  pop the top out of the stack 

template <class T>
bool SeqStack<T>::getTop(T& x) {
	if (isEmpty()) return false;
	x = elements[top];
	return true;
}
//  get the top

template <class T>
std::ostream& operator << (std::ostream& os, SeqStack<T>& s) {
	os << "top =" << s.top << std::endl;
	for (int i = 0; i <= s.top; i++) {
		os << i << ":" << s.elements[i] << std::endl;
	}
	return os;
}
//  output
