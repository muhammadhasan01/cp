#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const long long INF = 1e16;

int tc;
string s;
int pre[N];

void solve() {
    cin >> s;
    int n = s.length();
    s = "#" + s;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + (s[i] == '+' ? 1 : -1);
    }
    long long ans = 0;
    long long cur = 0;
    for (int i = 1; i <= n; i++) {
        if (pre[i] + cur < 0) {
            ans += (1LL) * i;
            ++cur;
        }
    }
    ans += (1LL) * n;
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