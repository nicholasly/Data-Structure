#ifndef CIR_LIST_H
#define CIR_LIST_H

#include <iostream>
#include "LinearList.h"
template <class T>
struct CircLinkNode {
	T data;
	CircLinkNode<T> * link;
	CircLinkNode(CircLinkNode<T> * next = NULL) : link(next) {}
	CircLinkNode(T d, CircLinkNode<T> * next = NULL) : data(d), link(next) {}
};

template <class T>
class CircList : public LinearList<T> {
public:
	CircList();
	CircList(const T& x);
	CircList(CircList<T>& L);
	~CircList();
	int Length() const;
	bool IsEmpty() {return first->link == first ? true : false;}

	CircLinkNode<T> * getHead() const;
	void setHead(CircLinkNode<T> * p);
	CircLinkNode<T> * Search(T x);
	CircLinkNode<T> * Locate(int i);
	T& getData(int i) const;
	void setData(int i, T& x);
	bool Insert(int i, T& x);
	bool Remove(int i, T& x);
private:
	CircLinkNode<T> * first, * last;
};

#endif
