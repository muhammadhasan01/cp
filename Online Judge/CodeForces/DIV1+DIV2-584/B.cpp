#include <bits/stdc++.h>
using namespace std;

const int N = 105;
int n;
char s[N];
int a[N], b[N];
char c[N][N * 10];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        char last = s[i];
        c[i][0] = last;
        for (int j = 1; j <= 1000; j++) {
            if (j >= b[i]) {
                if ((j - b[i]) % a[i] == 0) {
                    last = (last == '1' ? '0' : '1');
                }
            }
            c[i][j] = last;
        }
    }
    int ans = 0;
    for (int j = 0; j <= 1000; j++) {
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            if (c[i][j] == '1') cur++;
        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';

    return 0;
}
