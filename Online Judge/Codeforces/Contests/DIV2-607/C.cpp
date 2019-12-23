#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;
const int N = 1e6 + 5;
int tc, x, n, pos;
string s;
char a[N];
long long ans = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> x >> s;
        n = s.length();
        s = '#' + s + '#';
        ans = n;
        pos = 0;
        for (int i = 1; i <= n; i++) {
            a[i] = s[i];
            pos++;
        }
        for (int i = 1; i <= x; i++) {
            if (a[i] == '1') {
                continue;
            } else if (a[i] == '2') {
                int j = i + 1;
                long long cnt = 0;
                long long len = ans - (1LL) * j + 1LL;
                while (pos <= x && cnt < len) {
                    a[++pos] = a[j++];
                    cnt++;
                }
                ans = (ans + len) % M;
            } else if (a[i] == '3') {
                int j = i + 1;
                long long cnt = 0;
                long long len = ans - (1LL) * j + 1LL;
                while (pos <= x && cnt < 2LL * len) {
                    a[++pos] = a[j++];
                    cnt++;
                }
                ans = (ans + 2LL * len) % M;
            }
        }
        cout << (ans % M + M) % M << '\n';
    }

    return 0;
}
