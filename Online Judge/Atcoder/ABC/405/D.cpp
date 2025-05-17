#include <bits/stdc++.h>

using namespace std;

const int DIR = 4;
const int DX[] = {0, 0, 1, -1};
const int DY[] = {1, -1, 0, 0};
const char CC[] = {'<', '>', '^', 'v'};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] == 'E') {
                q.emplace(i, j);
            }
        }
    }
    auto ans = a;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int dir = 0; dir < DIR; dir++) {
            int cx = x + DX[dir];
            int cy = y + DY[dir];
            if (cx < 0 || cy < 0 || cx >= h || cy >= w) {
                continue;
            }
            if (ans[cx][cy] != '.') {
                continue;
            }
            ans[cx][cy] = CC[dir];
            q.emplace(cx, cy);
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
    
    return 0;
}