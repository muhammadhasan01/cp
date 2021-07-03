#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, a, b;
    cin >> n >> a >> b;
    if (b == 1) {
        cout << "Yes" << '\n';
        return;
    }
    map<long long, bool> mp;
    long long cur = 1;
    while (cur <= n) {
        mp[cur % b] = true;
        if (a == 1) {
            break;
        }
        cur = (cur * a);
    }
    cout << (mp.count(n % b) ? "Yes" : "No") << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}