#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<long long> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p.rbegin(), p.rend());
    vector<long long> pre(n);
    for (int i = 0; i < n; i++) {
        pre[i] = (i > 0 ? pre[i - 1] + p[i] : p[i]);
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        int L = x - y - 1, R = x - 1;
        cout << pre[R] - (L >= 0 ? pre[L] : 0LL) << '\n';
    }
    
    return 0;
}