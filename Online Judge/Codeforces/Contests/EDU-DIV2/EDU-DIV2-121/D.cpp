#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    vector<int> pre(2 * n + 1);
    vector<int> suf(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for (int x = 1, sum = 0; x <= n; x++) {
        for (int y = sum; y < sum + cnt[x]; y++) {
            pre[y] = sum;
        }
        sum += cnt[x];
    }
    for (int x = n + 1; x <= 2 * n; x++) {
        pre[x] = pre[x - 1];
    }
    for (int x = n, sum = 0; x >= 1; x--) {
        for (int y = sum; y < sum + cnt[x]; y++) {
            suf[y] = sum;
        }
        sum += cnt[x];
    }
    for (int x = n + 1; x <= 2 * n; x++) {
        suf[x] = suf[x - 1];
    }
    int need = INT_MAX;
    for (int l = 1; l <= 2 * n; l <<= 1) {
        for (int r = 1; r <= 2 * n; r <<= 1) {
            int len = n - pre[l] - suf[r];
            if (len < 0) {
                continue;
            }
            int mid = 1;
            while (mid < len) {
                mid <<= 1;
            }
            need = min(need, l + r + mid);
        }
    }
    cout << need - n << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        solve();
    }

    return 0;
}