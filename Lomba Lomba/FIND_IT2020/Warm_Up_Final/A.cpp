#include <bits/stdc++.h>

using namespace std;

int tc;
int n;

void solve() {
    cin >> n;
    vector<int> v;
    for (int i = n + 1; i <= n + 10; i++) {
        if (i & 1) v.emplace_back(i);
    }
    for (int i = 0; i < 3; i++) {
        cout << v[i] << (i == 2 ? '\n' : ' ');
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