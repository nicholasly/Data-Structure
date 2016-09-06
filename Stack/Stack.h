#ifndef STACK_H
#define STACK_H
#include <iostream>
template <class T>
class Stack {
public:
	Stack() {}
	//  constructor
	virtual void Push(const T& x) = 0;
	//  push a element into the stack
	virtual bool Pop(T& x) = 0;
	//  pop the top out of the stack 
	virtual bool getTop(T& x) const = 0;
	//  get the top
	virtual bool isEmpty() const = 0;
	//  judge if the stack is empty
	virtual bool isFull() const = 0;
	//  judge is the stack is full
	virtual int getSize() const = 0;
	//  get the size of the stack 
};

#endif