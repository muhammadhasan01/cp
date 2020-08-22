#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const char CC[3] = {'R', 'P', 'S'};

int tc;
int n;
char s[N];
int pre[N][3];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int it = 0; it < 3; it++) {
            pre[i][it] = pre[i - 1][it];
            if (s[i] == CC[it])
                pre[i][it]++;
        }
    }
    int ans = 0;
    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            if (x + y > n) break;
            int z = n - x - y;
            int res = pre[x][2]; // S
            res += (pre[x + y][0] - pre[x][0]); // R
            res += (pre[x + y + z][1] - pre[x + y][1]); // P
            int ser = pre[x][1]; // P
            ser += (pre[x + y][2] - pre[x][2]); // S
            ser += (pre[x + y + z][0] - pre[x + y][0]); // R
            if (res > ser)
                ++ans;
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}