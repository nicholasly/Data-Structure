	#include <iostream>
	#include <cstdio>
	using namespace std;
	const int maxsize = 10001;
	int a[maxsize] = {0};
	int b[maxsize] = {0};
	int find(int t, int num) {
		for (int i = 0; i < num; i++)
			if (a[i] == t) return i;
		return -1;
	}
	void swap(int m, int n) {
		int t = m;
		m = n;
		n = t;
	}
	int main() {
		int i, j, n, num, order;
		int t;
		while (cin >> n) {
			num = 0;
			for (i = 0; i < n; i++) {
				a[i] = b[i] = 0;
			}
			for (i = 0; i < n; i++) {
				scanf("%d", &t);
				order = find(t, num);
				if (order == -1) {
					a[num] = t;
					b[num++] = 1;
				}
				else {
					b[order]++;
				}
			}
			for (i = 1; i < num; i++) {
				for (j = n - 1; j >= i; j--) {
					if (a[j - 1] > a[j]) {
						swap(a[i], a[j]);
						swap(b[i], b[j]);
					}
				}
			}
			for (i = 0; i < num; i++)
				printf("%d %d\n", a[i], b[i]);
		}
		return 0;
	}
