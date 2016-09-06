#ifndef LINKED_STACK_H
#define LINKED_STACK_H
#include <iostream>
#include "LinkedList.h"
#include "Stack.h"

template <class T>
class LinkedStack : public Stack<T> {
public:
	LinkedStack() : top(NULL) {}
	//  constructor
	~LinkedStack() {
		makeEmpty();
	}
	//  destructor
	void Push(T& x);
	//  push an element into the stack
	bool Pop(T& x);
	//  pop the top
	bool getTop(T& x) const;
	//  get the top
	bool isEmpty() const {
		return (top == NULL) ? true : false;
	}
	int getSize() const;
	//  get the size
	void makeEmpty();
	//  clear the stack
	friend std::ostream& operator << (std::ostream& os, LinkedStack<T>& s);
	//  output the stack
private:
	LinkNode<T> * top;
	//  the pointer of the top
};

#endif
