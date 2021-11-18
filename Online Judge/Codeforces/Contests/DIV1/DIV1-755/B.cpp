#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    auto query = [&](int l, int r) {
        cout << "? " << l << " " << r << endl;
        long long ret;
        cin >> ret;
        return ret;
    };
    int l = 1, r = n, at = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (query(1, mid) > 0) {
            r = mid - 1;
        } else {
            l = mid + 1;
            at = mid;
        }
    }
    int pi = at;
    int dij = query(pi, n) - query(pi + 1, n);
    int pj = pi + dij + 1;
    int djk = query(pj, n) - query(pj + 1, n);
    int pk = pj + djk;
    cout << "! " << pi << " " << pj << " " << pk << endl;
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