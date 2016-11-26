#include <iostream>
#include <string>
#include <queue>
using namespace std;
struct square {
    int x, y, num;
};
int direction[8][2] = { { -2,-1 }, { -2,1 }, { -1,2 }, { 1,2 }, { 2,1 }, { 2,-1 }, { 1,-2 }, { -1,-2 } };
void BFS(int fx, int fy, int ex, int ey, string m, string n) {
    int i, j;
    square t;
    queue<square> q;
    t.x = fx;
    t.y = fy;
    t.num = 0;
    bool map[8][8];
    for (i = 0; i < 8; i++) {
        for (j = 0; i < 8; j++) {
            map[i][j] = false;
        }
    }
    q.push(t);
    cout << t.x << " " << t.y << endl;
    while (!q.empty()) {
        t = q.front();
        q.pop();
        cout << t.x << " " << t.y << endl;
        if (t.x == ex && t.y == ey) {
            cout << "To get from " << m << " to " << n << " takes " << t.num
                << " knight moves." << endl;
            return;
        }
        for (i = 0; i < 8; i++) {
            if (!map[t.x + direction[i][0]][t.y + direction[i][1]]) continue;
            if (t.x + direction[i][0] >= 0 && t.x + direction[i][0] <= 7 &&
                t.y + direction[i][1] >= 0 && t.y + direction[i][1] <= 7) {
                square p;
                p.x = t.x + direction[i][0];
                p.y = t.y + direction[i][1];
                map[t.x + direction[i][0]][t.y + direction[i][1]] = true;
                p.num = t.num + 1;
                q.push(p);
            }
        }
    }

}
int main() {
    int T;
    cin >> T;
    string a, b;
    int fx, fy, ex, ey;
    while (T--) {
        cin >> a >> b;
        fx = a[0] - 'a';
        fy = a[1] - '1';
        ex = b[0] - 'a';
        ey = b[1] - '1';
        BFS(fx, fy, ex, ey, a, b);
    }
    return 0;
}