#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 5;
int tc;
int n, k;
char a[N];
bool pos[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int len = n / 2 - k + 1;
        for (int i = 1; i <= len; i++) {
            pos[i] = 0;
            pos[i + len] = 1;
        }
        for (int i = 2 * len + 1; i <= n; i += 2) {
            pos[i] = 0;
            pos[i + 1] = 1;
        }
        vector<pair<int, int>> ans;
        for (int i = 1; i <= n; i++) {
            if (pos[i] && a[i] == '(') {
                for (int j = i + 1; j <= n; j++) {
                    if (a[j] == ')') {
                        ans.push_back({i, j});
                        reverse(a + i, a + j + 1);
                        break;
                    }
                }
            } else if (!pos[i] && a[i] == ')') {
                for (int j = i + 1; j <= n; j++) {
                    if (a[j] == '(') {
                        ans.push_back({i, j});
                        reverse(a + i, a + j + 1);
                        break;
                    }
                }
            }
        }
        cout << ans.size() << '\n';
        for (auto e : ans) {
            cout << e.first << " " << e.second << '\n';
        }
    }

    return 0;
}
