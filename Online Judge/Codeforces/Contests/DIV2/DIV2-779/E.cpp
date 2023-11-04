#include <bits/stdc++.h>

using namespace std;

const int K = 4;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    int A = n * n;
    vector<pair<int, int>> pos(A + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            pos[x] = {i, j};
        }
    }
    vector<vector<char>> ans(n + 1, vector<char>(n + 1));
    auto [si, sj] = pos[A];
    ans[si][sj] = 'M';
    vector<tuple<int, int, int>> P(K);
    for (int i = 0; i < K; i++) {
        int x = (i % 2 == 0 ? 1 : -1);
        int y = (i < 2 ? 1 : -1);
        P[i] = make_tuple(x * si + y * sj, si, sj);
    }
    for (int val = A - 1; val >= 1; val--) {
        auto [xi, xj] = pos[val];
        bool valid = true;
        for (int i = 0; i < K; i++) {
            auto [_, ci, cj] = P[i];
            if (abs(ci - xi) + abs(cj - xj) > k) {
                valid = false;
                break;
            }
        }
        if (valid) {
            ans[xi][xj] = 'M';
            for (int i = 0; i < K; i++) {
                int x = (i % 2 == 0 ? 1 : -1);
                int y = (i < 2 ? 1 : -1);
                P[i] = max(P[i], make_tuple(x * xi + y * xj, xi, xj));
            }
        } else {
            ans[xi][xj] = 'G';
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
    
    return 0;
}