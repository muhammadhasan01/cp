#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int x = -1, y = -1, m, n;

int k[N * N + 5];
int g[N][N];
string s;

long long cnt[N][N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    getline(cin, s);
    for (int i = 0; i < (int) s.size(); i++) {
        if (isdigit(s[i]) && x == -1) {
            x = s[i] - '0' + 1;
        } else if (isdigit(s[i]) && y == -1) {
            y = s[i] - '0' + 1;
        }
    }
    getline(cin, s);
    int hm = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        if (isdigit(s[i])) {
            m = s[i] - '0';
            hm++;
        }
    }
    if (hm > 1) m = 10;
    else m = (s[0] - '0');
    getline(cin, s);
    int len = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == '0') {
            k[++len] = 0;
        } else if (s[i] == '1') {
            k[++len] = 1;
        }
    }
    n = len;
    for (int i = 1; i <= n; i++) {
        g[1][i]=k[i];
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> g[i][j];
        }
    }

    //cerr << n << " and " << m << '\n';

    /*cout << '\n';
    cerr << n << " and " << m << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << g[i][j] << (j == n ? '\n': ' ');
        }
    }*/

    for (int e=0;e<=m;e++) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                if (e == 1 && g[i][j]) cnt[i][j][e] = 1;
                else if (e>1) {
                    for (int a=1;a<=n;a++) {
                        if (g[i][a]) cnt[i][j][e] += cnt[a][j][e-1];
                    }
                }
            }
        }
    }
    cout << cnt[x][y][m] << endl;
    return 0;
}
