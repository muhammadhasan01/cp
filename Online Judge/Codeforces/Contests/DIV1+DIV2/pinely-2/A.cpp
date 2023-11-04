#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a, q;
    cin >> n >> a >> q;
    vector<int> notif(q);
    for (int i = 0; i < q; i++) {
        char cc;
        cin >> cc;
        notif[i] = (cc == '+' ? 1 : -1);
    }

    auto checkYes = [&]() -> bool {
        int cnt = a;
        if (cnt == n) {
            return true;
        }
        for (int x : notif) {
            cnt += x;
            cnt = min(n, cnt);
            cnt = max(0, cnt);
            if (cnt == n) {
                return true;
            }
        }
        return cnt == n;
    };

    auto checkMaybe = [&]() -> bool {
        int cnt = a;
        for (int x : notif) {
            cnt += max(0, x);
        }
        return cnt >= n;
    };

    if (checkYes()) {
        cout << "YES" << '\n';
        return;
    }
    if (checkMaybe()) {
        cout << "MAYBE" << '\n';
        return;
    }
    cout << "NO" << '\n';
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