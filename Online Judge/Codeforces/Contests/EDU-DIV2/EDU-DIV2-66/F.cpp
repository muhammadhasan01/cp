#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<long long> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    vector<int> R(n + 2);
    R[n + 1] = n;
    vector<int> last(n + 1, n + 1);
    for (int i = n; i >= 1; i--) {
        R[i] = min(R[i + 1], last[a[i]] - 1);
        last[a[i]] = i;
    }

    auto check = [&](int l, int r) -> bool {
        if (l <= 0 || R[l] < r || r > n) {
            return false;
        }
        int len = (r - l + 1);
        long long expected = 1LL * len * (len + 1) / 2;
        long long actual = pre[r] - pre[l - 1];
        return expected == actual;
    };

    vector<int> ones;
    ones.emplace_back(0);
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            ones.emplace_back(i);
        }
    }
    ones.emplace_back(n + 1);
    int len = (int) ones.size();
    int ans = 0;
    for (int i = 1; i + 1 < len; i++) {
        ++ans;
        for (int j = ones[i] + 1, mx = 1; j < ones[i + 1]; j++) {
            mx = max(mx, a[j]);
            ans += check(j - mx + 1, j);
        }
        for (int j = ones[i] - 1, mx = 1; j > ones[i - 1]; j--) {
            mx = max(mx, a[j]);
            ans += check(j, j + mx - 1);
        }
    }
    cout << ans << '\n';
    
    return 0;
}