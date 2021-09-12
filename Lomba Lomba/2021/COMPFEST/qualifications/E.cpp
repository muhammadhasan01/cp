#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> v(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] %= m;
    }
    sort(v.begin(), v.begin() + n);
    for (int i = n; i < 2 * n; i++) {
        v[i] = v[i - n];
    }
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        a[i % n] = v[i];
    }
    auto get = [&](int x, int y) -> long long {
        if (x > y) {
            swap(x, y);
        }
        return min(y - x, x + m - y);
    };
    vector<long long> pre(2 * n);
    for (int i = 1; i < 2 * n; i++) {
        pre[i] = pre[i - 1] + get(v[i - 1], v[i]);
    }
    long long ans = INF;
    for (int i = n - 1; i < 2 * n; i++) {
        ans = min(ans, pre[i] - pre[i - n + 1]);
    }
    cout << ans << '\n';

    return 0;
}