#include <bits/stdc++.h>

using namespace std;

int countDistinct(string& p) {
    int n = (int) p.size();
    set<string> S;
    for (int i = 0; i < n; i++) {
        string cur = "";
        for (int j = i; j < n; j++) {
            cur += p[j];
            S.emplace(cur);
        }
    }
    return (int) S.size();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 30 * (i + 1); j++) {
            if (i < n - 1) {
                s[i] += (j == i ? "X" : "O");
            } else {
                s[i] += (j & 1 ? "X" : "O");
            }
        }
        cout << s[i] << endl;
    }
    map<int, pair<int, int>> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string cur = s[i] + s[j];
            int val = countDistinct(cur);
            assert(mp.find(val) == mp.end());
            mp[val] = {i, j};
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int val;
        cin >> val;
        auto [x, y] = mp[val];
        cout << x + 1 << ' ' << y + 1 << endl;
    }
    
    return 0;
}