#ifndef STATICLIST_H
#define STATICLIST_H
#include <iostream>

const int maxSize = 100;
template <class T>
struct SLinkNode {
	T data;
	int link;  //   the first address of the current allocated space
};

template <class T>
class StaticList {
private:
	SLinkNode<T> elem[maxSize];
	int avil;
public:
	void InitList();
	int Length();
	//  calculate the length of the static list
	int Search(T x);
	//  Search the node which has given value in the static list
	int Locate(int i);
	//  Search the ith node in the static list
	bool Append(T x);
	//  Add a new node to the end of the static list
	bool Insert(int i, T x);
	//  Insert a new node after the ith node
	bool Remove(int i);
	//  Release the ith node
	bool IsEmpty();
	//  Judge if the list is empty
};

#endif