#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
int tc;
int n;
string s[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<int> ans;
        vector<int> v[5], l(5);
        vector<bool> vis(n + 5);
        bool flag = false;
        map<string, int> m;
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            if (m[s[i]] > 0 && !flag) {
                vis[m[s[i]]] = 1;
                vis[i] = 1;
                reverse(s[i].begin(), s[i].end());
                ans.push_back(i);
                if (m[s[i]] > 0) {
                    flag = true;
                }
            }
            m[s[i]] = i;
            int len = s[i].length();
            char x = s[i][0], y = s[i][len - 1];
            if (x == '0' && y == '0') {
                v[1].push_back(i);
            } else if (x == '0' && y == '1') {
                v[2].push_back(i);
            } else if (x == '1' && y == '0') {
                v[3].push_back(i);
            } else {
                v[4].push_back(i);
            }
            reverse(s[i].begin(), s[i].end());
            if (m[s[i]] > 0) {
                vis[i] = 1;
                vis[m[s[i]]] = 1;
            }
        }
        if (flag) {
            cout << -1 << '\n';
            continue;
        }
        for (int i = 1; i <= 4; i++) {
            l[i] = (int) v[i].size();
        }
        if (l[1] > 0 && l[2] == l[3] && l[2] == 0 && l[4] > 0) {
            cout << -1 << '\n';
            continue;
        }
        int dif = abs(l[2] - l[3]);
        if (dif <= 1) {
            cout << ans.size() << '\n';
            for (auto e : ans) {
                cout << e << ' ';
            }
            cout << '\n';
            continue;
        }
        dif /= 2;
        int x = (l[2] > l[3] ? 2 : 3);
        int pos = 0;
        for (int i = 0; i < l[x]; i++) {
            int k = v[x][i];
            if (vis[k]) continue;
            ans.push_back(k);
            pos++;
            if (pos == dif) break;
        }
        if (pos != dif) {
            cout << -1 << '\n';
            continue;
        }
        cout << ans.size() << '\n';
        for (auto e : ans) {
            cout << e << ' ';
        }
        cout << '\n';
    }

    return 0;
}
