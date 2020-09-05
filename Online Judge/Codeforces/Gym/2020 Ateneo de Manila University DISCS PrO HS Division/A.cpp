#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s; cin >> s;
    int cnt = 0;
    for (char c : s) {
        if (c == 'X') {
            ++cnt;
        }
    }
    if (cnt <= 1) {
        cout << 0 << '\n';
        return 0;
    }
    int n = s.length();
    s += s;
    int ans = INF;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') continue;
        int last = -1;
        for (int j = i + 1; j < i + n; j++) {
            if (s[j] == '.') continue;
            last = j;
        }
        assert(last != -1);
        int res = 0;
        for (int j = i; j <= last; j++)
            if (s[j] == '.') ++res;
        ans = min(ans, res);
    }
    cout << ans << '\n';

    return 0;
}