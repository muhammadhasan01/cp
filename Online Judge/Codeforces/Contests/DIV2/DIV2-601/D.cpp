#include <bits/stdc++.h>

using namespace std;

const int N = 105;
int tc;
int r, c, k;
char a[N][N], ans[N][N];
int v[N];
int curi, cnt;

char av[63];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 10; i++) {
        av[i] = char(i + int('0'));
    }
    for (int i = 10; i < 10 + 26; i++) {
        av[i] = char(i - 10 + int('a'));
        av[i + 26] = char(i - 10 + int('A'));
    }

    cin >> tc;
    while (tc--) {
        cin >> r >> c >> k;
        int cnt = 0;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                cin >> a[i][j];
                ans[i][j] = '#';
                if (a[i][j] == 'R') cnt++;
            }
        }
        int num = cnt / k, res = cnt % k;
        for (int i = 0; i < k; i++) {
            v[i] = num + (i < res ? 1 : 0);
        }
        curi = 0;
        cnt = 0;
        for (int i = 1; i <= r; i++) {
            if (i & 1) {
                for (int j = 1; j <= c; j++) {
                    ans[i][j] = av[curi];
                    if (a[i][j] == 'R') {
                        cnt++;
                    }
                    if (v[curi] == cnt) {
                        cnt = 0;
                        curi = min(curi + 1, k - 1);
                    }
                }
            } else {
                for (int j = c; j >= 1; j--) {
                    ans[i][j] = av[curi];
                    if (a[i][j] == 'R') {
                        cnt++;
                    }
                    if (v[curi] == cnt) {
                        cnt = 0;
                        curi = min(curi + 1, k - 1);
                    }
                }
            }
        }
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                cout << ans[i][j];
            }
            cout << '\n';
        }
    }

    return 0;
}
