#include <bits/stdc++.h>

using namespace std;

const int N = 15;
int tc, n;
string p[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        map<string, int> m;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            m[p[i]]++;
        }
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            if (m[p[i]] == 1) continue;
            string cur = p[i];
            for (int j = 0; j < 4; j++) {
                bool flag = false;
                for (int k = 0; k < 10; k++) {
                    p[i][j] = char(int('0') + k);
                    if (!m[p[i]]) {
                        m[cur]--;
                        m[p[i]]++;
                        ans++;
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }
        }
        cout << ans << '\n';
        for (int i = 1; i <= n; i++) {
            cout << p[i] << '\n';
        }
    }

    return 0;
}
