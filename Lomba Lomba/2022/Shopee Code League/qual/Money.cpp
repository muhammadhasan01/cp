// author: Mastre
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    map<string, ll> money;
    for (int i = 0; i < n; i++) {
        string s;
        ll a;
        cin >> s >> a;
        money[s] = a;
    }

    while (q--) {
        string a, b;
        ll x;
        cin >> a >> b >> x;
        if (money[a] >= x) {
            money[a] -= x;
            money[b] += x;
        }
    }
    for (auto& x : money) {
        cout << x.fi << ' ' << x.se << '\n';
    }

    return 0;
}