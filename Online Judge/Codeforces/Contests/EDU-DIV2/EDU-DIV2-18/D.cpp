#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
int q;

ll get_log(ll x) {
    ll ret = 1;
    while (x % 2 == 0) {
        ret *= 2LL;
        x /= 2;
    }
    return ret;
}

void go_up(ll& x) {
    if (x == (n + 1) / 2) return;
    ll dif = 2LL * get_log(x);
    ll y = x;
    while (y % 2 == 0) y /= 2;
    if (y % 4 == 3) x -= dif;
    x = (x + (x + dif)) / 2;
}

void go_child(ll& x, bool left) {
    if (x % 2 != 0) return;
    ll dif = get_log(x) / 2LL;
    if (left) dif = -dif;
    x += dif;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    while (q--) {
        ll res; cin >> res;
        string str; cin >> str;
        for (int i = 0; i < (int) str.size(); i++) {
            char cc = str[i];
            if (cc == 'U')
                go_up(res);
            else if (cc == 'L')
                go_child(res, true);
            else if (cc == 'R')
                go_child(res, false);
        }
        cout << res << '\n';
    }

    return 0;
}