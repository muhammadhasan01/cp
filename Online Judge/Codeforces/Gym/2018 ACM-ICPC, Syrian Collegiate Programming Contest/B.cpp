#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(2, vector<int>(2));
    for (int it = 0; it < 2; it++) {
        string str;
        cin >> str;
        for (char cc : str) {
            v[it][(int) (cc - '0')]++;
        }
    }
    cout << min(v[0][0], v[1][1]) + min(v[0][1], v[1][0]) << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("hamming.in", "r", stdin);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}