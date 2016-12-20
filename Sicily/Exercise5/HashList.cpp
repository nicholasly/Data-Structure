#include <cstdio>
const int count = 13;
struct key {
	int data;
	key * next;
	key(int d, key * link = NULL) {
		data = d;
		next = link;
	}
};
int main() {
	int n, i, t, mod;
	key * head[count];
	scanf("%d", &n);
	while(n) {
		for (i = 0; i < count; i++) head[i] = NULL;
		for (i = 0; i < n; i++) {
			scanf("%d", &t);
			mod = t % count;
			key * newkey = new key(t, NULL);
			if (head[mod] == NULL) {
				head[mod] = newkey;
			} else {
				key * p = head[mod];
				while (p->next != NULL) {
					p = p->next;
				}
				p->next = newkey;
			}
		}
		for (i = 0; i < count; i++) {
			if (head[i] == NULL) {
				printf("%d#NULL\n", i);
				continue;
			}
			printf("%d#%d", i, head[i]->data);
			key * p = head[i]->next;
			while (p != NULL) {
				printf(" %d", p->data);
				p = p->next;
			}
			printf("\n");
		}
		scanf("%d", &n);
	}
	return 0;
}