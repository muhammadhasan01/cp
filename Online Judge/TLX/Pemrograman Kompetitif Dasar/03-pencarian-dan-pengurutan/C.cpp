#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    unordered_map<string, string> mp;
    for (int i = 0; i < n; i++) {
        string s, val;
        cin >> s >> val;
        mp[s] = val;
    }
    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        if (mp.count(s)) {
            cout << mp[s] << '\n';
        } else {
            cout << "NIHIL" << '\n';
        }
    }
    
    return 0;
}