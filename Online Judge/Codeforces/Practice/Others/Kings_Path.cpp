#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int bound = 1e9;
int p0, q0, p1, q1;
int n;

int dx[8] = {1, -1, 1, -1, 0, 1, 0, -1};
int dy[8] = {1, -1, -1, 1, 1, 0, -1, 0};

map<pair<int,int>, int> dist;
map<pair<int,int>, bool> vis;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> p0 >> q0 >> p1 >> q1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        for (int j = a; j <= b; j++) vis[{r, j}] = 1;
    }
    queue<pair<int,int>> q;
    q.push({p0, q0});
    dist[{p0, q0}] = 1;
    while (!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int kx = cur.first + dx[i];
            int ky = cur.second + dy[i];
            if (kx > bound || kx < 1) continue;
            if (ky > bound || ky < 1) continue;
            if (vis[{kx, ky}] == 0) continue;
            if (dist[{kx, ky}] > 0) continue;
            q.push({kx, ky});
            dist[{kx, ky}] = dist[cur] + 1;
        }
    }
    cout << dist[{p1, q1}] - 1 << '\n';

    return 0;
}
