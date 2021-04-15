#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int K = 26;

int n, k;
char s[N];
int pre[N][K];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 0; j < K; j++) {
            pre[i][j] = pre[i - 1][j];
        }
        int num = s[i] - 'a';
        pre[i][num]++;
    }
    bool ok = true;
    for (int i = 0; i < K; i++) {
        if (pre[n][i] % k == 0) continue;
        ok = false;
        break;
    }
    if (ok) {
        for (int i = 1; i <= n; i++) {
            cout << s[i];
        }
        cout << '\n';
        return;
    }
    for (int i = n; i >= 1; i--) {
        int num = s[i] - 'a';
        pre[i][num]--;
        for (int j = num + 1; j < K; j++) {
            pre[i][j]++;
            bool ok = true;
            int rem = n - i;
            for (int x = 0; x < K; x++) {
                if (pre[i][x] % k == 0) continue;
                int need = k - pre[i][x] % k;
                if (rem >= need) {
                    rem -= need;
                } else {
                    ok = false;
                    break;
                }
            }
            if (ok && rem % k == 0) {
                for (int it = 1; it < i; it++) cout << s[it];
                cout << char(int('a') + j);
                for (int it = 0; it < rem; it++) cout << 'a';
                for (int x = 0; x < K; x++) {
                    if (pre[i][x] % k == 0) continue;
                    int need = k - pre[i][x] % k;
                    for (int it = 0; it < need; it++) cout << char(int('a') + x);
                }
                cout << '\n';
                return;
            }
            pre[i][j]--;
        }
    }
    cout << -1 << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}