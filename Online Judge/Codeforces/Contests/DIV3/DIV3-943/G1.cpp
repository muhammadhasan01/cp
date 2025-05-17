#include <bits/stdc++.h>

using namespace std;

vector<int> LPS(string& s) {
    int n = (int) s.length();
    vector<int> lps(n);
    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = lps[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        lps[i] = j;
    }
    return lps;
}

vector<bool> KMPSearch(string& txt, string& pat) {
    int n = (int) txt.size();
    int m = (int) pat.size();
    vector<int> lps = LPS(pat);
    vector<bool> pos(n);
    for (int i = 0, j = 0; i < n; ) {
        if (pat[j] == txt[i]) {
            i++, j++;
        }
        if (j == m) {
            pos[i - j] = true;
            j = lps[j - 1];
        } else if (pat[j] != txt[i]) {
            if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return pos;
}

void solve() {
    int n, k;
    cin >> n >> k >> k;
    string s;
    cin >> s;

    auto can = [&](int len) -> bool {
        string p = s.substr(0, len);
        vector<bool> pos = KMPSearch(s, p); 
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (pos[i]) {
                cnt++;
                i += len - 1;
            }
        }
        return cnt >= k;
    };

    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}