#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int n;
vector<ll> vec;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        vec.push_back(a);
    }
    vector<ll> sisa(n + 1, 0LL);
    for (int i = n - 1; i >= 0; i--) {
        sisa[i] = sisa[i + 1] + vec[i];
    }

    vector<ll> cur = {0LL, 0LL, 0LL};
    ll ans = 0;
    function<void(int)> dfs = [&](int pos) -> void {
        if (ans >= min((cur[0] + cur[1] + sisa[pos]) / 2, min(cur[0] + sisa[pos], cur[1] + sisa[pos]))) return;
        if (pos == n) {
            if (cur[0] == cur[1]) ans = max(ans, cur[0]);
            return;
        }
        for (int i = 0; i <= 2; i++) {
            cur[i] += vec[pos];
            dfs(pos + 1);
            cur[i] -= vec[pos];
        }
    };
    dfs(0);
    cout << ans << '\n';

    return 0;
}