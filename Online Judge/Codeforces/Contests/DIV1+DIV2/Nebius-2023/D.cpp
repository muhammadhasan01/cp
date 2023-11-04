#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    int n, m;
    cin >> n >> m;
    int d = m / 4;

    auto getMin = [&](string& s) -> int {
        int ret = 0;
        for (int i = 0; i < m; i++) {
            ret += s[i] == '1';
        }
        int cnt = 0;
        for (int i = 1; i < m && cnt < d; i++) {
            if (s[i] == '1' && s[i - 1] == '1') {
                ret--;
                cnt++;
                i++;
            }
        }
        return ret;
    };

    auto getMax = [&](string& s) -> int {
        vector<bool> vis(m);
        int cnt = 0;
        int ret = 0;
        for (int i = 1; i < m && cnt < d; i++) {
            if (vis[i] || vis[i - 1]) {
                continue;
            }
            if ((s[i] == '1' && s[i - 1] == '0') || (s[i] == '0' && s[i - 1] == '1')) {
                vis[i] = 1;
                vis[i - 1] = 1;
                cnt++;
                ret++;
            }
            if (s[i] == '0' && s[i - 1] == '0') {
                vis[i] = 1;
                vis[i - 1] = 1;
                cnt++;
            }
        }
        for (int i = 1; i < m && cnt < d; i++) {
            if (vis[i] || vis[i - 1]) {
                continue;
            }
            if (s[i] == '1' && s[i - 1] == '1') {
                vis[i] = 1;
                vis[i - 1] = 1;
                cnt++;
                ret++;
            }
        }
        for (int i = 0; i < m; i++) {
            if (vis[i]) {
                continue;
            }
            ret += (s[i] == '1');
        }
        return ret;
    };

    int mn = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mn += getMin(s);
        mx += getMax(s);
    }
    cout << mn << ' ' << mx << '\n';
    
    return 0;
}