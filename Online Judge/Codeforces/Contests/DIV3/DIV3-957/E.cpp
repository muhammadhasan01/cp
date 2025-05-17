#include <bits/stdc++.h>

using namespace std;

const int NMAX = 1e2 + 5;
const int B = 10000;

vector<pair<int, int>> ans[NMAX];

void solve() {
    int n;
    cin >> n;
    cout << (int) ans[n].size() << '\n';
    for (auto [x, y] : ans[n]) {
        cout << x << " " << y << '\n';
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int b = 1; b <= B - 1; b++) {
        ans[1].emplace_back(b + 1, b);
    }
    for (int n = 2; n < NMAX; n++) {
        string N = to_string(n);
        int len = (int) N.size();
        for (int b = 1; b <= B; b++) {
            int l = 1, r = B, pos = -1;
            while (l <= r) {
                int a = (l + r) >> 1;
                long long res = 1LL * a * n - b;
                long long actual = (int) to_string(res).size();
                long long expected = max(0LL, 1LL * len * a - b);
                if (res < 0 || expected <= actual) {
                    l = a + 1;
                    pos = a;
                } else {
                    r = a - 1;
                }
            }
            if (pos != -1) {
                int a = pos;
                long long res = a * n - b;
                long long actual = (int) to_string(res).size();
                long long expected = max(0LL, 1LL * len * a - b);
                if (actual == expected) {
                    string str = "";
                    for (int j = 0; j < expected; j++) {
                        str += N[j % len];
                    }
                    if (stoll(str) == res) {
                        ans[n].emplace_back(a, b);
                    }
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