#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int tc;
int n;
char s[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    int cur = 0;
    int ans = 0;
    for (int i = 1; i <= n - ans; i++) {
        if (s[i] == '(') {
            ++cur;
        } else {
            if (cur == 0) {
                ++ans;
            } else {
                --cur;
            }
        }
    }
    cout << ans << '\n';
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