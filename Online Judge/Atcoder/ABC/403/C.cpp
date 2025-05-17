#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<bool> perm(N + 1);
    set<ll> granted;
    while (Q--) {
        int t, x, y;
        cin >> t >> x;
        if (t == 1) {
            cin >> y;
            if (!perm[x]) {
                ll key = (ll(x) << 32) | y;
                granted.insert(key);
            }
        } else if (t == 2) {
            perm[x] = 1;
        } else {
            cin >> y;
            if (perm[x] || granted.count((ll(x) << 32) | y)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
    
    return 0;
}