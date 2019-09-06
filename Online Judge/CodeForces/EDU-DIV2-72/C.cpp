#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int tc;
string s;
int n;
int sz[N];
long long pre[50];
int place[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pre[0] = 1;
    for (int i = 1; i <= 36; i++) {
        pre[i] = pre[i - 1] * 2;
    }

    cin >> tc;
    while (tc--) {
        cin >> s;
        int n = s.length();
        s = '#' + s;
        long long ans = 0;
        vector<int> pos;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '1') {
                place[i] = i;
            } else {
                place[i] = place[i - 1];
            }
        }
        for (int i = n; i >= 1; i--) {
            long long cur = 0;
            for (int j = i; j >= 1; j--) {
                int k = i - j;
                if (s[j] == '1') {
                    if (k >= 20) break;
                    cur += pre[k];
                }
                if (cur > n) break;
                if (j != place[j]) {
                    int m = place[j] + 1;
                    if (cur <= i - m + 1 && cur > 2) ans++;
                    j = m;
                } else if (cur == k + 1){
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
