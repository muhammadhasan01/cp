#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int n;
char s[N];
int ans[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    map<pair<int, int>, int> mp;
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'D') {
            x++;
        } else {
            y++;
        }
        int g = __gcd(x, y);
        ans[i] = 1;
        pair<int, int> cur = make_pair(x / g, y / g);
        if (mp.count(cur)) {
            ans[i] = 1 + ans[mp[cur]];
        }
        mp[cur] = i;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
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