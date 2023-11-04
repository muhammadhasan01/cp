#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    char cur = 'a';
    set<char> turns;
    for (int i = 0; i < n; i++) {
        if (cur >= s[i]) {
            continue;
        }
        int dif = min(k, s[i] - cur);
        k -= dif;
        for (char cc = s[i]; dif > 0; cc--, dif--) {
            turns.emplace(cc);
        }
        if (k == 0) {
            break;
        }
        cur = s[i];
    }
    for (int i = 0; i < n; i++) {
        while (turns.find(s[i]) != turns.end()) {
            s[i]--;
        }
    }
    cout << s << '\n';
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