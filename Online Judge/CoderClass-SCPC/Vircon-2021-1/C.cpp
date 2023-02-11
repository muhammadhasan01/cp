#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<string, int> mp;
    int total = 0;
    for (int i = 0; i < n; i++) {
        string str;
        int val;
        cin >> str >> val;
        mp[str] += val;
        total += val;
        cin >> str;
    }
    vector<int> v;
    for (auto& [str, val] : mp) {
        v.emplace_back(val);
    }
    int mx = 0;
    int len = v.size();
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            mx = max(mx, v[i] + v[j]);
        }
    }
    cout << total - mx << ' ' << "Juta" << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}