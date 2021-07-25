#include <bits/stdc++.h>

using namespace std;

const int K = 60;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);    

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (x % 2 == 0) {
            x /= 2;
            a[i]++;
        }
        a[i] = K - a[i];
    }
    int m = K + 5;
    vector<int> bit(m);
    auto add = [&](int x, int val) -> void {
        for ( ; x > 0; x -= x & -x) {
            bit[x] += val;
        }
    };
    auto get = [&](int x) -> int {
        int ret = 0;
        for ( ; x < m; x += x & -x) {
            ret += bit[x];
        }
        return ret;
    };
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        add(a[i], 1);
        ans += get(a[i] + 1);
    }
    cout << ans << '\n';

    return 0;
}