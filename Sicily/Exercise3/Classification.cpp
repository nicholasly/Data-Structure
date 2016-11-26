#include <iostream>
using namespace std;
int times;
bool Edge[101][101];
int kind[101][101];
int Find[101];
int visited[101];
void DFS(int i, int n) {
    times++;
    for (int j = 0; j < n; j++) {
        if (Edge[i][j]) {
            if (visited[j] == 0) {
                Find[j] = times;
                visited[j] = 1;
                kind[i][j] = 1;
                DFS(j, n);
            }
            else if (visited[j] == 1)
                kind[i][j] = 3;
            else if (Find[i] < Find[j])
                kind[i][j] = 2;
        }
    }
    visited[i] = 2;
    times++;
}
int main() {
    int n, m, i, j, u, v;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        visited[i] = 0;
        Find[i] = 0;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            Edge[i][j] = false;
            kind[i][j] = 0;
        }
    }
    for (i = 0; i < m; i++) {
        cin >> u >> v;
        Edge[u - 1][v - 1] = true;
    }
    times = 1;
    for (i = 0; i < n; i++) {
        if (visited[i] == 0) {
            Find[i] = times;
            visited[i] = 1;
            DFS(i, n);
        }
    }
    int k;
    cin >> k;
    for (i = 0; i < k; i++) {
        cin >> u >> v;
        cout << "edge (" << u << "," << v << ") is ";
        if (kind[u - 1][v - 1] == 0) cout << "Cross Edge" << endl;
        else if (kind[u - 1][v - 1] == 1) cout << "Tree Edge" << endl;
        else if (kind[u - 1][v - 1] == 2) cout << "Down Edge" << endl;
        else if (kind[u - 1][v - 1] == 3) cout << "Back Edge" << endl;
    }
    cin >> n;
    return 0;
}