#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int INF = 2e9;

int n, m;
string s[N];

int check(int x) {
    int ret = 0;
    for (int i = 2; i <= n; i++) {
        int cur = INF;
        for (int k = 0; k < m; k++) {
            bool flag = true;
            for (int j = 0; j < m; j++) {
                if (s[i][(j + k) % m] != s[1][(j + x) % m]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cur = k;
                break;
            }
        }
        if (cur == INF) return INF;
        ret += cur;
    }
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    m = s[1].length();
    int ans = INF;
    for (int x = 0; x < m; x++) {
        ans = min(ans, x + check(x));
    }
    if (ans == INF) ans = -1;
    cout << ans << '\n';

    return 0;
}