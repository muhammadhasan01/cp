#include <bits/stdc++.h>

using namespace std;

int n, k;

void solve() {
    cin >> n >> k;
    vector<int> v;
    for (int i = (k + 1) / 2; i < k; i++) {
        v.emplace_back(i);
    }
    for (int i = k + 1; i <= n; i++) {
        v.emplace_back(i);
    }
    int len = v.size();
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << v[i] << " \n"[i == len - 1];
    }
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