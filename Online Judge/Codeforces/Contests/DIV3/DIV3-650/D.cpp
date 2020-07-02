#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int tc;
int n, m;
int b[N];
char ans[N];
string s;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> s;
        n = s.length();
        cin >> m;
        for (int i = 1; i <= m; i++) {
            cin >> b[i];
        }
        sort(s.begin(), s.end(), greater<char>());
        vector<pair<char, int>> v;
        char cur = s[0];
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (cur == s[i]) {
                ++cnt;
            } else {
                v.emplace_back(cur, cnt);
                cur = s[i];
                cnt = 1;
            }
        }
        v.emplace_back(cur, cnt);
        vector<vector<int>> sz;
        vector<bool> vis(m + 1);
        for (int it = 1; it <= m; it++) {
            vector<int> pos;
            for (int i = 1; i <= m; i++) {
                if (b[i] == 0 && !vis[i]) {
                    vis[i] = true;
                    pos.emplace_back(i);
                }
            }
            if (pos.empty()) break;
            sz.emplace_back(pos);
            for (auto e : pos) {
                for (int i = 1; i <= m; i++) {
                    if (vis[i]) continue;
                    b[i] -= abs(i - e);
                }
            }
        }
        int len_1 = v.size();
        int len_2 = sz.size();
        for (int i = 0, j = 0; i < len_1 && j < len_2; i++) {
            int len = sz[j].size();
            if (len <= v[i].second) {
                for (auto e : sz[j]) {
                    ans[e] = v[i].first;
                }
                ++j;
            }
        }
        for (int i = 1; i <= m; i++) {
            cout << ans[i];
        }
        cout << '\n';
    }

    return 0;
}