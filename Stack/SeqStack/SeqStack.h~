#ifndef SEQ_STACK
#define SEQ_STACK
#include <iostream>
#include <assert.h>
#include "Stack.h"

const int stackIncreament = 20;

template <class T>
class SeqStack : public Stack<T> {
public:
	SeqStack(int sz = 50);
	//  constructor to creata an array 
	~SeqStack() {
		delete []elements;
	}
	//  destructor
	void Push(const T& x);
	//  push a element into the stack
	bool Pop(T& x);
	//  pop the top out of the stack 
	bool getTop(T& x);
	//  get the top
	bool isEmpty() const {
		return (top == -1) ? true : false;
	}
	//  judge if the stack is empty
	bool isFull() const = 0;
	//  judge is the stack is full
    int getSize() const = 0;
    //  get the size of the stack
    void makeEmpty() {
    	top = -1;
    }
    //  clear the stack
    friend std::ostream& operator << (std::ostream& os, SeqStack<T>& s);
 private:
	T * elements;
	int top;
	int maxSize;
	void overflowProcess();
	//  measures to deal with the overflow
};

#endif
