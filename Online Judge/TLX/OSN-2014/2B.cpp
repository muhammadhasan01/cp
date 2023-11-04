#include <bits/stdc++.h>

using namespace std;

const int R = 1e3 + 5;
const int C = 1e3 + 5;
const int B = 1e3 + 5;
const int K = 4;
const int DX[] = {0, 0, 1, -1};
const int DY[] = {1, -1, 0, 0};

char grid[R][C];
int color[R][C];
vector<int> adj[B];
int dist[B];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    int r, c;
    cin >> r >> c;
    int sx = -1, sy = -1;
    int tx = -1, ty = -1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                sx = i, sy = j;
            } else if (grid[i][j] == 'T') {
                tx = i, ty = j;
            }
        }
    }
    memset(color, -1, sizeof(color));
    int curColor = 0;

    function<void(int, int)> colorLand = [&](int sx, int sy) {
        queue<pair<int, int>> q;
        color[sx][sy] = curColor;
        q.emplace(sx, sy);
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < K; i++) {
                int cx = x + DX[i];
                int cy = y + DY[i];
                if (cx < 0 || cx >= r || cy < 0 || cy >= c) {
                    continue;
                }
                if (grid[cx][cy] == '.') {
                    continue;
                }
                if (color[cx][cy] == -1) {
                    color[cx][cy] = curColor;
                    q.emplace(cx, cy);
                } 
            }
        }
    };

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == '.') {
                continue;
            }
            if (color[i][j] == -1) {
                colorLand(i, j);
                curColor++;
            }
        }
    }
    for (int i = 0; i < r; i++) {
        int lst = -1;
        for (int j = 0; j < c; j++) {
            if (color[i][j] == -1) {
                continue;
            }
            if (lst != -1 && lst != color[i][j]) {
                adj[lst].emplace_back(color[i][j]);
                adj[color[i][j]].emplace_back(lst);
            }
            lst = color[i][j];
        }
    }
    for (int j = 0; j < c; j++) {
        int lst = -1;
        for (int i = 0; i < r; i++) {
            if (color[i][j] == -1) {
                continue;
            }
            if (lst != -1 && lst != color[i][j]) {
                adj[lst].emplace_back(color[i][j]);
                adj[color[i][j]].emplace_back(lst);
            }
            lst = color[i][j];   
        }
    }

    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.emplace(color[sx][sy]);
    dist[color[sx][sy]] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = 1 + dist[u];
                q.emplace(v);
            }
        }
    }
    cout << dist[color[tx][ty]] << '\n';
    
    return 0;
}