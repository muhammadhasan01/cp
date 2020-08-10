#include <bits/stdc++.h>

using namespace std;

int tc;
string s[2];

void solve() {
    vector<int> res(2);
    int n; cin >> n;
    for (int it = 0; it < 2; it++) {
        cin >> s[it];
        for (auto e : s[it]) {
            e = tolower(e);
            if (e == 'a' || e == 'i' || e == 'u' || e == 'e' || e == 'o') {
                ++res[it];
            }
        }
    }
    if (res[0] == res[1]) {
        cout << "Equal" << '\n';
    } else {
        cout << (res[0] > res[1] ? "First" : "Second") << " " << "String" << '\n';
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}