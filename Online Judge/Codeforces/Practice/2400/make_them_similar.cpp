#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int K = 15;

int n;
int a[N];
map<vector<int>, int> mp[2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int it = 0; it < 2; it++) {
        int add = (it == 0 ? 0 : K);
        for (int mask = 0; mask < (1 << K); mask++) {
            vector<int> val(n);
            int nmask = (mask << add);
            for (int i = 1; i <= n; i++) {
                int cur = (a[i] ^ nmask);
                int cnt = 0;
                for (int j = 0; j < K; j++) {
                    if (cur & (1 << (j + add))) {
                        cnt++;
                    }
                }
                val[i - 1] = cnt;
            }
            int sub = val[0];
            for (int i = 0; i < n; i++) {
                val[i] -= sub;
            }
            mp[it][val] = (mask << add);
        }
    }
    for (auto& [v, mask] : mp[0]) {
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = -v[i];
        }
        if (mp[1].count(res)) {
            int ans = mask + mp[1][res];
            cout << ans << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';

    return 0;
}