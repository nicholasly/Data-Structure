#include <iostream>
const int Infinity = 100;
using namespace std;
int main() {
    int n, m, i, j, k, a, b, w, min;
    cin >> n >> m;
    int * dist = new int[n];
    int ** Edge = new int *[n];
    for (i = 0; i < n; i++) {
        Edge[i] = new int[n];
        dist[i] = 0;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) Edge[i][j] = Infinity;
            else Edge[i][j] = 0;
        }
    }
    for (i = 0; i < m; i++) {
        cin >> a >> b;
        Edge[a - 1][b - 1] = Edge[b - 1][a - 1] = 1;
    }
    bool * S = new bool[n];
    for (i = 0; i < n; i++) {
        dist[i] = Edge[0][i];
        S[i] = false;
    }
    S[0] = true;
    dist[0] = 0;
    for (i = 0; i < n - 1; i++) {
        min = Infinity;
        int u = 0;
        for (j = 0; j < n; j++) {
            if (S[j] == false && dist[j] < min) {
                u = j;
                min = dist[j];
            }
        }
        S[u] = true;
        for (k = 0; k < n; k++) {
            w = Edge[u][k];
            if (S[k] == false && w < Infinity && dist[u] + w < dist[k]) {
                dist[k] = dist[u] + w;
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (dist[i] == Infinity) cout << "-1 ";
        else cout << dist[i] << " ";
    }
    cout << endl;
    for (i = 0; i < n; i++) {
        delete[] Edge[i];
    }
    delete[] Edge;
    delete[] dist;
    delete[] S;
    return 0;
}