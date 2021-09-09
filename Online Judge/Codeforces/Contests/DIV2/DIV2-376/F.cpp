#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    vector<int> bit(N);
    auto add = [&](int x, int val) -> void {
        for ( ; x > 0; x -= x & -x) {
            bit[x] += val;
        }
    };
    auto get = [&](int x) -> long long {
        long long ret = 0;
        for ( ; x < N; x += x & -x) {
            ret += bit[x];
        }
        return ret;
    };
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        add(a[i], 1);
        if (i + 1 < n && a[i] == a[i + 1]) {
            continue;
        }
        long long cur = 0;
        for (int j = a[i]; j < N; j += a[i]) {
            long long now = get(j) * a[i];
            if (now == 0) {
                break;
            }
            cur += now;   
        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';
    
    return 0;
}