#include <bits/stdc++.h>

using namespace std;

void solve() {
    vector<int> v(4);
    for (int i = 0; i < 4; i++) {
        cin >> v[i];
    }
    vector<int> w = v;
    sort(w.begin(), w.end());
    int x = max(v[0], v[1]);
    int y = max(v[2], v[3]);
    if (x > y) swap(x, y);
    cout << (x == w[2] && y == w[3] ? "YES" : "NO") << '\n';
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