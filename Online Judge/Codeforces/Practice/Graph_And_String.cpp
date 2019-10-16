#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int n, m;
string ans;
set<int> s[N];

bool check() {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int k = abs(ans[i - 1] - ans[j - 1]);
            if (k <= 1 && s[i].find(j) == s[i].end()) {
                return false;
            } else if (k == 2 && s[i].find(j) != s[i].end()){
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    ans.resize(n, 'a');
    for (int i = 1; i <= n; i++) s[i].insert(i);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        s[u].insert(v);
        s[v].insert(u);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (s[i].find(j) == s[i].end()) {
                for (int x = 1; x <= n; x++) {
                    if (s[i] == s[x]) ans[x - 1] = 'a';
                    else if (s[j] == s[x]) ans[x - 1] = 'c';
                    else ans[x - 1] = 'b';
                }
                if (check()) {
                    cout << "Yes" << '\n';
                    cout << ans << '\n';
                    return 0;
                }
                cout << "No" << '\n';
                return 0;
            }
        }
    }
    cout << "Yes" << '\n';
    cout << ans << '\n';

    return 0;
}
