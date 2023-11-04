#include <bits/stdc++.h>

using namespace std;

const int K = 26;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<set<int>> pos(K);
    for (int i = 0; i < n; i++) {
        int num = s[i] - 'a';
        pos[num].emplace(i);
    }
    string ans = "";
    for (int i = 0; i < n; i++) {
        int num = s[i] - 'a';
        if (pos[num].empty()) {
            continue;
        }
        int rgt = *pos[num].rbegin();
        bool take = true;
        int mostLeft = n + 1;
        for (int x = num + 1; x < K; x++) {
            auto it = pos[x].upper_bound(i);
            if (it == pos[x].end()) {
                continue;
            }
            if (*it < rgt) {
                mostLeft = min(mostLeft, *it);
                take = false;
            }
        }
        if (mostLeft != n + 1) {
            for (int x = num - 1; x >= 0; x--) {
                if (pos[x].empty()) {
                    continue;
                }
                int R = *pos[x].rbegin();
                if (i < R && R < mostLeft) {
                    take = true;
                    break;
                }
            }
        }
        if (take) {
            ans += s[i];
            pos[num].clear();
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}