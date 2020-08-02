#include <bits/stdc++.h>

using namespace std;

void solve() {
    bool neg = false;
    vector<vector<long long>> v(2);
    vector<int> len(2);
    for (int i = 0; i < 2; i++) {
        long long x;
        cin >> x;
        if (x < 0) neg ^= 1;
        x = abs(x);
        long long cur = 1;
        while (x > 0) {
            long long val = (x % 10) * cur;
            if (val) v[i].emplace_back(val);
            cur *= 10;
            x /= 10;
        }
        len[i] = v[i].size();
    }
    char pm = (neg ? '-' : '+');
    if (neg) cout << pm;
    for (int i = 0; i < len[0]; i++) {
        for (int j = 0; j < len[1]; j++) {
            cout << v[0][i] << " x " << v[1][j];
            if (i == len[0] - 1 && j == len[1] - 1) {
                cout << '\n';
            } else {
                cout << " " << pm << " ";
            }
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}