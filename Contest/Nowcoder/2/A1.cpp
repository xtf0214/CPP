#include <bits/stdc++.h>
using namespace std;
const int N = 51;
int G[N][N];
int dy = 3, dx = 5;
int vec[4][2]{{dy, dx}, {dy, -dx}, {-dy, -dx}, {-dy, dx}};
bool layer[100];
struct Node {
    int y, x, st;
};
void print() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cout << (G[i][j] ? "  " : "[]") << "\n"[j != N - 1];
    cout << endl;
}
int main() {
    queue<Node> q;
    q.push({N / 2, N / 2, 0});
    while (!q.empty()) {
        Node t = q.front();
        q.pop();
        if (!layer[t.st]) {
            print();
            layer[t.st] = true;
            cin.get();
        }
        G[t.y][t.x] = 1;
        for (auto &[ty, tx] : vec) {
            int ny = t.y + ty, nx = t.x + tx;
            if (nx < 0 || nx >= N || ny < 0 || ny >= N || G[ny][nx] == 1)
                continue;
            q.push({ny, nx, t.st + 1});
        }
    }
    print();
    return 0;
}