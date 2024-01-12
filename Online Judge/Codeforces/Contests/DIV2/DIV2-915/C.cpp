#include <bits/stdc++.h>

using namespace std;

const int A = 26;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> pos(A);
    for (int i = 0; i < n; i++) {
        int x = s[i] - 'a';
        pos[x].emplace_back(i);
    }
    vector<int> idx;
    int cntLarge = 0;
    for (int x = A - 1; x >= 0; x--) {
        if (pos[x].empty()) {
            continue;
        }
        if (cntLarge == 0) {
            cntLarge += (int) pos[x].size();
        }
        for (int i : pos[x]) {
            if (idx.empty() || idx.back() < i) {
                idx.emplace_back(i);
            }
        }
    }
    string t = s;
    int len = (int) idx.size();
    for (int i = 0, j = len - 1; i < len; i++, j--) {
        t[idx[i]] = s[idx[j]];
    }
    if (!is_sorted(t.begin(), t.end())) {
        cout << -1 << '\n';
        return;
    }
    cout << len - cntLarge << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}