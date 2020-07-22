#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int tc;
int n;
char a[N], b[N];

void change(char& c) {
    c = (c == '1' ? '0' : '1');
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vector<int> ans;
    int x = 0;
    int l = 1, r = n, pos = n;
    while (pos >= 1) {
        if (!x) {
            if (a[r] == b[pos]) {
                r--, pos--;
            } else {
                x ^= 1;
                if (a[l] == b[pos]) {
                    change(a[l]);
                    ans.emplace_back(1);
                }
                ans.emplace_back(pos);
            }
        } else {
            if (a[l] != b[pos]) {
                l++, pos--;
            } else {
                x ^= 1;
                if (a[r] != b[pos]) {
                    change(a[r]);
                    ans.emplace_back(1);
                }
                ans.emplace_back(pos);
            }
        }
    }
    cout << ans.size() << ' ';
    for (auto& e : ans) cout << e << ' ';
    cout << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}