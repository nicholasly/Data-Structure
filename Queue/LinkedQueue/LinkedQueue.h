#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H
#include <iostream>
#include "LinkedList.h"
#include "Queue.h"
template <class T>
class LinkedQueue : public Queue<T> {
public:
	LinkedQueue() : front(NULL), rear(NULL) {}
	~LinkedQueue() {
		makeEmpty();
	}
	bool EnQueue(const T& x);
	bool DeQueue(T& x);
	bool getFront(T& x) const;
	void makeEmpty();
	bool IsEmpty() const {
		return front == NULL;
	}
	int getSize() const;
	friend std::ostream& operator << (ostream& os, LinkedQueue<T>& Q);
private:
	LinkNode<T> * front, * rear;
};

#endif
