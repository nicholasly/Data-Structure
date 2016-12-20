#include <iostream>
#include <set> 
#include <cstdio>
using namespace std;
int main() {
    set<int> s1, s2, s3, s4;
    int n, k, i, j, t;
    scanf("%d", &n);
    scanf("%d", &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &t);
        if (t >= 5000000) s1.insert(t);
        else if (t >= 0 && t < 5000000) s2.insert(t);
        else if (t >= -5000000 && t < 0) s3.insert(t);
        else s4.insert(t);
    }
    int l1 = s1.size();
    int l2 = s2.size();
    int l3 = s3.size();
    int l4 = s4.size();
    // printf("l1 = %d\n", l1);
    // printf("l2 = %d\n", l2);
    // printf("l3 = %d\n", l3);
    // printf("l4 = %d\n", l4);
    // for (set<int>::iterator it = s1.begin(); it != s1.end(); ++it) {
    // 	printf("%d\n", *it);
    // }
    // for (set<int>::iterator it = s2.begin(); it != s2.end(); ++it) {
    // 	printf("%d\n", *it);
    // }
    // for (set<int>::iterator it = s3.begin(); it != s3.end(); ++it) {
    // 	printf("%d\n", *it);
    // }
    // for (set<int>::iterator it = s4.begin(); it != s4.end(); ++it) {
    // 	printf("%d\n", *it);
    // }
    if (l1 >= k) {
    	i = l1 - k;
		set<int>::iterator it = s1.begin();
		for (j = 0; j < i; j++) it++;
		printf("%d\n", *it);
    }
    else if (l1 + l2 >= k && l1 < k) {
    	i = l1 + l2 - k;
		set<int>::iterator it = s2.begin();
		for (j = 0; j < i; j++) it++;
		printf("%d\n", *it);
    }
    else if (l1 + l2 + l3 >= k && l1 + l2 < k) {
    	i = l1 + l2 + l3 - k;
		set<int>::iterator it = s3.begin();
		for (j = 0; j < i; j++) it++;
		printf("%d\n", *it);
    }
    else {
    	i = l1 + l2 + l3 + l4 - k;
		set<int>::iterator it = s4.begin();
		for (j = 0; j < i; j++) it++;
		printf("%d\n", *it);
    }
    return 0;
}
