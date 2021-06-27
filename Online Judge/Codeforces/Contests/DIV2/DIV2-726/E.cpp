#include <bits/stdc++.h>

using namespace std;

vector<int> z_function(string& s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> z = z_function(s);
    string ans;
    ans += s[0];
    for (int i = 1; i < n; i++) {
        if (i + z[i] >= n) {
            break;
        }
        if (s[i + z[i]] > s[z[i]]) {
            break;
        }
        ans += s[i];
    }
    while ((int) ans.size() < k) {
        ans += ans;
    }
    while ((int) ans.size() > k) {
        ans.pop_back();
    }
    cout << ans << '\n';

    return 0;
}