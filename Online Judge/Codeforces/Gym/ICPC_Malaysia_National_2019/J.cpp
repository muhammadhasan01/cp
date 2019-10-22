#include <bits/stdc++.h>

using namespace std;

vector<int> g[10];
int deg[10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    for (int i = 0; i < 5; i++) {
        string s;
        cin >> s;
        if (s[1] == '>') {
            int k = s[0] - 'A';
            int kk = s[2] - 'A';
            g[k].push_back(kk);
            deg[kk]++;
        } else if (s[1] == '<') {
            int k = s[0] - 'A';
            int kk = s[2] - 'A';
            g[kk].push_back(k);
            deg[k]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < 5; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }

    string ans = "";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans += char(u + int('A'));
        for (auto e : g[u]) {
            if (--deg[e] == 0) {
                q.push(e);
            }
        }
    }


    if ((int) ans.size() < 5) {
        puts("impossible");
    } else {
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }

    return 0;
}
