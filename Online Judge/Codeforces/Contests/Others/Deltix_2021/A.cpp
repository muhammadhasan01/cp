#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n, m;
char s[N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int rep = 0; rep < min(m, N); rep++) {
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            int num = 0;
            if (i - 1 >= 1 && s[i - 1] == '1') ++num;
            if (i + 1 <= n && s[i + 1] == '1') ++num;
            if (num == 1) {
                v.emplace_back(i);
            }
        }
        if (v.empty()) break;
        for (int id : v) {
            s[id] = '1';
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << s[i];
    }
    cout << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}