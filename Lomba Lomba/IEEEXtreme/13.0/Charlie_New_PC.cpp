#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int tc;
ll b;
int n, k;
const ll inf = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> b >> n;
        vector<int> len(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> len[i];
        }
        vector<vector<ll>> v(n + 1);
        for (int i = 1; i <= n; i++) {
            v[i].resize(len[i] + 1);
            for (int j = 1; j <= len[i]; j++) {
                cin >> v[i][j];
            }
        }
        vector<ll> st[n + 3];
        st[0].push_back(0);
        st[n + 1].push_back(0);
        for (int i = 1; i <= n / 2; i++) {
            for (auto e : st[i - 1]) {
                for (int j = 1; j <= len[i]; j++) {
                    ll cur = e + v[i][j];
                    if (cur > b) continue;
                    st[i].push_back(cur);
                }
            }
        }
        for (int i = n; i >= n / 2 + 1; i--) {
            for (auto e : st[i + 1]) {
                for (int j = 1; j <= len[i]; j++) {
                    ll cur = e + v[i][j];
                    if (cur > b) continue;
                    st[i].push_back(cur);
                }
            }
        }

        int pos1 = n / 2, pos2 = n / 2 + 1;
        ll ans = 0;

        if (st[pos1].size() < st[pos2].size()) {
            sort(st[pos2].begin(), st[pos2].end());
            for (auto e : st[pos1]) {
                auto it = upper_bound(st[pos2].begin(), st[pos2].end(), b - e);
                if (it != st[pos2].begin()) {
                    it--;
                    ans = max(ans, *it + e);
                }
            }
        } else {
            sort(st[pos1].begin(), st[pos1].end());
            for (auto e : st[pos2]) {
                auto it = upper_bound(st[pos1].begin(), st[pos1].end(), b - e);
                if (it != st[pos1].begin()) {
                    it--;
                    ans = max(ans, *it + e);
                }
            }
        }


        cout << ans << '\n';
    }

    return 0;
}
