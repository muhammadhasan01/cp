#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<long long> b(n + 1);
    vector<long long> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        pre[i] = pre[i - 1] + b[i];
    }

    auto getRange = [&](int l, int r) -> long long {
        return pre[r] - pre[l - 1];
    };

    vector<long long> ans(n + 5);
    vector<long long> cnt(n + 5);
    for (int i = 1; i <= n; i++) {
        int l = i, r = n, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (a[i] > getRange(i, mid)) {
                l = mid + 1;
                at = mid;
            } else {
                r = mid - 1;
            }
        }
        if (at == -1) {
            ans[i] += a[i];
            continue;
        }
        long long dif = a[i] - getRange(i, at);
        cnt[i]++;
        cnt[at + 1]--;
        ans[at + 1] += dif;
    }
    for (int i = 1; i <= n; i++) {
        cnt[i] += cnt[i - 1];
        ans[i] += cnt[i] * b[i];
        cout << ans[i] << " \n"[i == n];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}