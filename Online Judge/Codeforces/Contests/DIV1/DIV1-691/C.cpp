#include <bits/stdc++.h>

using namespace std;

const int K = 3;

void solve() {
    int n, m;
    cin >> n >> m;
    int A = n * n;
    vector<array<int, K>> a(A);
    for (int i = 0; i < A; i++) {
        int x;
        cin >> x;
        a[i][0] = i / n;
        a[i][1] = i % n;
        a[i][2] = x - 1;
    }
    vector<int> shift(K);
    vector<int> order(K);
    iota(order.begin(), order.end(), 0);
    for (int i = 0; i < m; i++) {
        char cc;
        cin >> cc;
        if (cc == 'R') {
            shift[1] = (shift[1] + 1) % n;
        } else if (cc == 'L') {
            shift[1] = (shift[1] + n - 1) % n;
        } else if (cc == 'U') {
            shift[0] = (shift[0] + n - 1)  % n;
        } else if (cc == 'D') {
            shift[0] = (shift[0] + 1) % n;
        } else if (cc == 'I') {
            swap(order[1], order[2]);
            swap(shift[1], shift[2]);
        } else if (cc == 'C') {
            swap(order[0], order[2]);
            swap(shift[0], shift[2]);
        }
    }
    vector<vector<int>> ans(n, vector<int>(n));
    for (int i = 0; i < A; i++) {
        vector<int> res(K);
        for (int j = 0; j < K; j++) {
            res[j] = (a[i][order[j]] + shift[j]) % n;
        }
        ans[res[0]][res[1]] = res[2];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] + 1 << " \n"[j == n - 1];
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}