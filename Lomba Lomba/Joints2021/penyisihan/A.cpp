#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n,0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

string rem(string s) {
    int len = s.size();
    if (s.back() == '0') {
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] == '0') {
                s[i] = '9';
            } else {
                if (i == 0 && s[i] == '1') {
                    return string(len - 1, '9');
                }
                s[i]--;
                break;
            }
        }
        return s;
    } else {
        s[len - 1]--;
        return s;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, p;
    cin >> s >> p;
    vector<int> v = prefix_function(p);
    int n = s.size(), m = p.size();
    int len = m - v.back();
    string ans = p;
    string add = p.substr(v.back());
    string dep = "";
    while ((int) ans.size() < n) {
        if ((int) ans.size() + len < n) {
            ans += add;
        } else if ((int) ans.size() + len == n) {
            string cur = ans + add;
            if (cur > s) {
                dep = s.substr(0, n - (int) ans.size());
                cur = dep + ans;
                if (cur > s) {
                    dep = rem(dep);
                }
                break;
            } else {
                ans += add;
            }
        } else {
            dep = s.substr(0, n - (int) ans.size());
            string cur = dep + ans;
            if (cur > s) {
                dep = rem(dep);
            }
            break;
        }
    }
    cout << dep + ans << '\n';
 
    return 0;
}