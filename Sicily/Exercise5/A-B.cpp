#include <iostream>
#include <cstdio>
using namespace std;
const int MAXSIZE = 1000000;
bool A[MAXSIZE];
bool B[MAXSIZE];
int main() {
	int T, n, m, i, j, t, num;
	scanf("%d", &T);
	while (T--) {
		j = 0;
		num = 0;
		for (i = 0; i < MAXSIZE; i++) {
			A[i] = false;
			B[i] = false;
		}
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", &t);
			if (t > j) j = t;
			A[t] = true;
		}
		scanf("%d", &m);
		for (i = 0; i < m; i++) {
			scanf("%d", &t);
			if (t > j) j = t;
			B[t] = true;
		}
		for (i = 0; i <= j; i++) {
			if (!B[i] && A[i]) {
				printf("%d ", i);
				num++;
			}
		}
		if (!num) printf("-1 ");
		printf("\n");
	}
	return 0;
}Binary Search