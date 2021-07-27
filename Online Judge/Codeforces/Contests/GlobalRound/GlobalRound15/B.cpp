#include <bits/stdc++.h>

using namespace std;

const int TAKE = 50;
const int K = 5;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> r(n, vector<int>(K));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < K; j++) {
            cin >> r[i][j];
        }
    }
    auto super = [&](int x, int y) -> bool {
        int ret = 0;
        for (int j = 0; j < K; j++) {
            if (r[x][j] < r[y][j]) {
                ret++;
            }
        }
        return ret >= 3;
    };
    int x = 0;
    for (int i = 1; i < n; i++) {
        if (!super(x, i)) {
            x = i;
        }
    }
    auto check = [&](int x) -> bool {
        vector<int> cnt(n);
        for (int j = 0; j < K; j++) {
            for (int i = 0; i < n; i++) {
                if (r[i][j] > r[x][j]) {
                    cnt[i]++;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (cnt[i] >= 3) {
                res++;
            }
        }
        return (res == n - 1);
    };
    cout << (check(x) ? x + 1 : -1) << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}