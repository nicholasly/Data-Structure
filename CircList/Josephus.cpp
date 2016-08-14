#include <iostream>
#include "CircList.h"
using namespace std;
template <class T>
void Josephus(CircList<T>& Js, int n, int m) {
	CircLinkNode<T> * p = Js.Locate(i), * pre = NULL;
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 1; j < m; j++) {
			pre = p;
			p = p->link;
		}
		cout << p->data << " ";
		pre->link = p->link;
		delete p;
		p = pre->link;
	}
}

void main() {
	CircList<int> clist;
	int i, n, m;
	cin >> n >> m;
	Josephus(clist, n, m);
}
