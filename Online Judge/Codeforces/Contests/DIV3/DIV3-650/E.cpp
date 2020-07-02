#include <bits/stdc++.h>

using namespace std;

int tc;
int n, k;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        vector<int> cnt(26);
        for (int i = 1; i <= n; i++) {
            char x;
            cin >> x;
            cnt[(int) (x - 'a')]++;
        }
        sort(cnt.begin(), cnt.end());
        for (int it = n; it >= 1; it--) {
            int part = __gcd(it, k);
            vector<int> sz(part, it / part);
            for (int j = 1; j < part; j++) {
                sz[j] += (j <= it % part);
            }
            sort(sz.begin(), sz.end());
            bool flag = false;
            vector<int> cntz = cnt;
            for (int i = 0, j = 0; i < 26; ++i) {
                if (sz[j] <= cntz[i]) {
                    cntz[i] -= sz[j];
                    --i, ++j;
                }
                if (j == part) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                cout << it << '\n';
                break;
            }
        }
    }

    return 0;
}