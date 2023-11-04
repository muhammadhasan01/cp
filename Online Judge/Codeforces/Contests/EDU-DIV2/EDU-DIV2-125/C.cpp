#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<int> rgt;
    for (int i = 0; i < n; i++) {
        if (s[i] == ')') {
            rgt.emplace(i);
        }
    }
    int cnt = 0;
    int rem = 0;
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            rem = 1;
            break;
        }
        if (s[i] == '(') {
            cnt++;
            i++;
        } else if (s[i] == ')') {
            auto it = rgt.upper_bound(i);
            if (it == rgt.end()) {
                rem = n - i;
                break;
            }
            cnt++;
            i = *it;
        }
    }
    cout << cnt << ' ' << rem << '\n';
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