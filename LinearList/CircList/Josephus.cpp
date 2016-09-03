#include <iostream>
#include "CircList.h"
using namespace std;
template <class T>
void Josephus(CircList<T>& Js, int n, int m) {
	CircLinkNode<T> * p = Js.Locate(1), * pre = NULL;
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

int main() {
	CircList<int> clist;
	int i, n, m;
	cin >> n >> m;
	for (i = 1; i <= n; i++) clist.Insert(i - 1, i);
	Josephus(clist, n, m);
	return 0;
}
