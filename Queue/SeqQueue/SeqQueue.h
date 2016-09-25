#ifndef SEQ_QUEUE_H
#define SEQ_QUEUE_H
#include <iostream>
#include "Queue.h"
template <class T>
class SeqQueue : public Queue<T> {
public:
	SeqQueue(int sz = 10);
	//  constructor
	~SeqQueue() {
		delete[] elements;
	}
	bool EnQueue(const T& x);
	bool DeQueue(T& x);
	bool getFront(T& x);
	void makeEmpty() {
		front = rear = 0;
	}
	bool IsEmpty() const {
		return front == rear; 
	}
	bool IsFull() const {
		return (rear + 1) % maxSize == front;
	}
	int getSize() const {
		return (rear - front + maxSize) % maxSize;
	}
	friend std::ostream& operator << (std::ostream& os, SeqQueue<T>& Q);
private:
	int rear, front;
	T * elements;
	int maxSize;
};

#endif