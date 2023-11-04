#include <bits/stdc++.h>

using namespace std;

const int K = 4;
const int DX[] = {0, 0, 1, -1};
const int DY[] = {1, -1, 0, 0};
const int N = 4;
const int M = N * N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<pair<int, int>> pos;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int A;
            cin >> A;
            if (A) {
                pos.emplace_back(i, j);
            }
        }
    }
    int ans = 0;
    for (int mask = 1; mask < (1 << M); mask++) {
        vector<vector<int>> on(N, vector<int>(N));
        for (int i = 0; i < M; i++) {
            if (mask & (1 << i)) {
                int r = i / N;
                int c = i % N;
                on[r][c] = 1;
            }
        }

        auto isEligible = [&]() -> bool {
            for (auto [x, y] : pos) {
                if (!on[x][y]) {
                    return false;
                }
            }
            int numColor = 0;
            vector<vector<bool>> vis(N, vector<bool>(N));
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (!on[i][j]) {
                        continue;
                    }
                    if (vis[i][j]) {
                        continue;
                    }
                    if (++numColor > 1) {
                        return false;
                    }
                    queue<pair<int, int>> q;
                    vis[i][j] = true;
                    q.emplace(i, j);
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        for (int k = 0; k < K; k++) {
                            int cx = x + DX[k];
                            int cy = y + DY[k];
                            if (cx < 0 || cy < 0 || cx >= N || cy >= N) {
                                continue;
                            }
                            if (!on[cx][cy]) {
                                continue;
                            }
                            if (vis[cx][cy]) {
                                continue;
                            }
                            vis[cx][cy] = 1;
                            q.emplace(cx, cy);
                        }
                    }
                }
            }
            {
                queue<pair<int, int>> q;
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        if (on[i][j]) {
                            continue;
                        }
                        if (i == 0 || j == 0 || i == N - 1 || j == N - 1) {
                            q.emplace(i, j);
                            vis[i][j] = true;
                        }
                    }
                }
                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();
                    for (int k = 0; k < K; k++) {
                        int cx = x + DX[k];
                        int cy = y + DY[k];
                        if (cx < 0 || cy < 0 || cx >= N || cy >= N) {
                            continue;
                        }
                        if (vis[cx][cy] || on[cx][cy]) {
                            continue;
                        }
                        q.emplace(cx, cy);
                        vis[cx][cy] = true;
                    }
                }
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        if (!on[i][j] && !vis[i][j]) {
                            return false;
                        }
                    }
                }
            }
            return true;
        };

        if (isEligible()) {
            ++ans;
        }
    }
    cout << ans << '\n';
    
    return 0;
}