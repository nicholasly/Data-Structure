#include <iostream>
#include "StaticList.h"
using namespace std;

template <class T>
void StaticList<T>::InitList() {
	elem[0].link = -1; avil = 1;
	for (int i = 1; i < maxSize - 1; i++) {
		elem[i].link = i + 1;
	}
	elem[maxSize - 1].link = -1;
}

template <class T>
int StaticList<T>::Length() {
	int p = elem[0].link;
	int i = 0;
	while (p != -1) {
		p = elem[p].link;
		i++;
	}
	return i;
}

template <class T>
int StaticList<T>::Search(T x) {
	int p = elem[0].link;
	while (p != -1) {
		if (elem[p].data == x) break;
		else p = elem[p].link;
	}
	return p;
}

template <class T>
int StaticList<T>::Locate(int i) {
	if (i < 0) return -1;
	if (i == 0) return 0;
	int j = 1, p = elem[0].link;
	while (p != -1 && j < i) {
		p = elem[p].link;
		j++;
	}
	return p;
}

template <class T>
bool StaticList<T>::Append(T x) {
	if (avil == -1) return false;
	int q = avil;
	avil = elem[avil].link;
	elem[q].data = x;
	elem[q].link = -1;
	int p = 0;
	while (elem[p].link != -1)
		p = elem[p].link;
	elem[p].link = q;
}

template <class T>
bool StaticList<T>::Insert(int i, T x) {
	int p = Locate(i);
	if (p == -1) return false;
	int q = avil;
	avil = elem[avil].link;
	elem[q].data = x;
	elem[q].link = elem[p].link;
	elem[p].link = q;
	return true;
}

template <class T>
bool StaticList<T>::Remove(int i) {
	int p = Locate(i - 1);
	if (p == -1) return false;
	int q = elem[p].link;
	elem[p].link = elem[q].link;
	elem[q].link = avil;
	avil = q;
	return true;
}

template <class T>
bool StaticList<T>::IsEmpty() {
	if (elem[0].linl == -1) return true;
	else return false;
}