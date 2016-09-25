#ifndef QUEUE_H
#define QUEUE_H
const int maxSize = 50;
template <class T>
class Queue {
public:
	Queue() {}
	//  constructor
	~Queue() {}
	//  destructor
	virtual void EnQueue(const T& x) = 0;
	//  new element x enter the queue
	virtual bool DeQueue(T& x) = 0;
	//  the front element leave the queue
	virtual bool getFront(T& x) = 0;
	//  get the value of the front element
	virtual bool IsEmpty() const = 0;
	//  judge if the queue is empty
	virtual bool IsFull() const = 0;
	//  judge if the queue is full
	virtual int getSize() const = 0;
	//  get the size of the queue	
};
//  the definition of class Queue 
#endif
