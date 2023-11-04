#include <bits/stdc++.h>

using namespace std;

const int K = 2;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> pre(K);
    vector<vector<int>> suf(K);
    for (int x = 0; x < K; x++) {
        for (int i = 1; i <= n; i++) {
            if (a[i] % K == x) {
                pre[x].emplace_back(i);
                if ((int) pre[x].size() == K) {
                    break;
                }
            }
        }
        for (int i = n; i >= 1; i--) {
            if (a[i] % K == x) {
                suf[x].emplace_back(i);
                if ((int) suf[x].size() == K) {
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] % 2 == 0) {
            continue;
        }
        for (int x = 0; x < K; x++) {
            if (pre[x].size() == K && pre[x][0] < i && pre[x][1] < i) {
                cout << "YES" << '\n';
                cout << pre[x][0] << ' ' << pre[x][1] << ' ' << i << '\n';
                return;
            }
            if (suf[x].size() == K && suf[x][0] > i && suf[x][1] > i) {
                cout << "YES" << '\n';
                cout << i << " " << suf[x][1] << " " << suf[x][0] << '\n';
                return;
            }
            if (!pre[x].empty() && !suf[x].empty() && pre[x][0] < i && i < suf[x][0]) {
                cout << "YES" << '\n';
                cout << pre[x][0] << ' ' << i << " " << suf[x][0] << '\n';
                return;
            }
        }
    }
    cout << "NO" << '\n';
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