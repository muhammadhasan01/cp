#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    string t;
    cin >> t;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int m = (int) t.length();
    vector<long long> cnt(m + 1);
    for (int i = 0; i < n; i++) {
        int pos = m - 1;
        int len = (int) s[i].length();
        for (int j = len - 1; j >= 0 && pos >= 0; j--) {
            if (s[i][j] == t[pos]) {
                pos--;
            }
        }
        cnt[pos + 1]++;
    }
    for (int i = 1; i <= m; i++) {
        cnt[i] += cnt[i - 1];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int pos = 0;
        int len = (int) s[i].length();
        for (int j = 0; j < len && pos < m; j++) {
            if (s[i][j] == t[pos]) {
                pos++;
            }
        }
        ans += cnt[pos];
    }
    cout << ans << '\n';
    
    return 0;
}