#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> s;
    if (k > n) {
        int kk = 100;
        for (auto e : s) {
            int pos = e - 'a';
            kk = min(pos, kk);
        }
        char mini = char(kk + int('a'));
        cout << s;
        for (int i = 1; i <= k - n; i++) cout << mini;
        cout << '\n';
    } else {
        vector<char> v;
        vector<bool> vis(30, 0);
        for (auto e : s) {
            int pos = e - 'a';
            if (vis[pos] == 0) {
                vis[pos] = 1;
                v.push_back(e);
            }
        }
        sort(v.begin(), v.end());
        for (int i = k - 1; i >= 0; i--) {
            auto it = upper_bound(v.begin(), v.end(), s[i]);
            if (it != v.end()) {
                cout << s.substr(0, i);
                cout << *it;
                for (int j = i + 1; j <= k - 1; j++) cout << v[0];
                cout << '\n';
                return 0;
            }
        }
    }

    return 0;
}
