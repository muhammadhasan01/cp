#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int j = i + m - 1;
        if (j >= n) {
            break;
        }
        if (s.substr(i, m) == t) {
            for (int k = i; k <= j; k++) {
                q.emplace(k);
                s[k] = '#';
            }
        }
    }

    auto check = [&](int pos) -> bool {
        int j = pos + m - 1;
        if (j >= n) {
            return false;
        }
        for (int i = pos, k = 0; i <= j; i++, k++) {
            if (s[i] == '#' || s[i] == t[k]) {
                continue;
            }
            return false;
        }
        return true;
    };

    while (!q.empty()) {
        int i = q.front();
        q.pop();
        int l = max(0, i - m + 1);
        for (int j = l; j <= i; j++) {
            int r = j + m - 1;
            if (r >= n) {
                break;
            }
            if (check(j)) {
                for (int k = j; k <= r; k++) {
                    if (s[k] != '#') {
                        q.emplace(k);
                    }
                    s[k] = '#';
                }
            }
        }
    }
    cout << (s == string(n, '#') ? "Yes" : "No") << '\n';
    
    return 0;
}