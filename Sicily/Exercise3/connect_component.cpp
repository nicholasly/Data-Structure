#include <iostream>
using namespace std;
const int MAX = 100;
int pre[MAX];
int find(int a) {
    if (pre[a] != a) {
        pre[a] = find(pre[a]);
    }
    return pre[a];
}
void join(int a, int b) {
    int x = find(a), y = find(b);
    if (x != y) pre[y] = x;
}
int main() {
    int n, m, i, a, b, num = 0;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        pre[i] = i;
    }
    for (i = 0; i < m; i++) {
        cin >> a >> b;
        join(a, b);
    }
    for (i = 0; i < n; i++) {
        if (pre[i] == i) num++;
    }
    cout << num << endl;
    return 0;
}