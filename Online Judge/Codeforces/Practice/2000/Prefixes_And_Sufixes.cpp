#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, len[N], cnt[N], lps[N];
char s[N];
int ans = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = strlen(s);
    for (int i = 1, j = 0; i < n; i++) {
        j = lps[i - 1];
        while (s[i] != s[j] && j > 0) j = lps[j - 1];
        if (s[i] == s[j]) j++;
        lps[i] = j;
    }
    int t = lps[n - 1];
    while (t) {
        len[++ans] = t;
        t = lps[t - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
        cnt[i + 1]++;
        cnt[lps[i]] += cnt[i + 1];
    }
    cout << ans + 1 << '\n';
    for (int i = ans; i >= 1; i--) {
        cout << len[i] << " " << cnt[len[i]] << '\n';
    }
    cout << n << " " << 1 << '\n';

    return 0;
}
