#include <bits/stdc++.h>

using namespace std;

const int A = 26;

map<int, string> mp;

void solve() {
    int n;
    cin >> n;
    cout << mp[n] << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 1; i <= A; i++) {
        for (int j = 1; j <= A; j++) {
            for (int k = 1; k <= A; k++) {
                int res = i + j + k;
                string cur = "";
                cur += char(int('a') + i - 1);
                cur += char(int('a') + j - 1);
                cur += char(int('a') + k - 1);
                if (mp.count(res)) {
                    mp[res] = min(mp[res], cur);
                } else {
                    mp[res] = cur;
                }
            }
        }
    }

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}