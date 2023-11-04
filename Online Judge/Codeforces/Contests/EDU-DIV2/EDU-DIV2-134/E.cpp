#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 20;
const int K = 10;

char s[N];
int pi[N];

void solve() {
    string str;
    cin >> str;
    int n = str.length();
    for (int i = 0; i < n; i++) {
        s[i] = str[i];
    }
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    int q;
    cin >> q;
    unordered_map<string, int> dp;
    while (q--) {
        string t;
        cin >> t;
        int m = t.length();
        for (int i = n; i < n + m; i++) {
            s[i] = t[i - n];
        }
        string cur = "";
        for (int i = n; i < n + m; i++) {
            cur += s[i];
            int j = pi[i - 1];
            if (dp.count(cur)) {
                j = dp[cur];
            } else {
                while (j > 0 && s[i] != s[j]) {
                    j = pi[j - 1];
                }
                dp[cur] = j;
            }
            if (s[i] == s[j]) {
                j++;
            }
            pi[i] = j;
        }
        for (int i = n; i < n + m; i++) {
            cout << pi[i] << " \n"[i == n + m - 1];
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}