#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

unordered_map<long long, int> mp;
long long pre[N];

void solve() {
    long long x;
    cin >> x;
    for (int i = 1; i < N; i++) {
        if (pre[i] >= x) break;
        if (mp[x - pre[i]] > 0) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i < N; i++) {
        pre[i] = 1LL * i * i * i;
        mp[pre[i]] = i;
    }

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}