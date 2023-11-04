#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> pp(N);
    for (int i = 2; i < N; i++) {
        if (pp[i] > 0) {
            continue;
        }
        for (int j = i; j < N; j += i) {
            pp[j] = i;
        }
    }
    vector<vector<int>> res(N);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;L
        cin >> x;
        while (x > 1) {
            int p = pp[x];
            int cnt = 0;
            while (x % p == 0) {
                x /= p;
                ++cnt;
            }
            res[p].emplace_back(cnt);
        }
    }
    long long ans = 1;
    for (int i = 1; i < N; i++) {
        if (res[i].empty()) {
            continue;
        }
        int len = res[i].size();
        if (len <= n - 2) {
            continue;
        }
        sort(res[i].begin(), res[i].end());
        int smallest = (len == n - 1 ? res[i][0] : res[i][1]);
        for (int it = 0; it < smallest; it++) {
            ans = (ans * i);
        }
    }
    cout << ans << '\n';
    
    return 0;
}