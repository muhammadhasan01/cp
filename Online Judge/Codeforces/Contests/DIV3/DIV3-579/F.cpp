#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 105;
int n;
ll r;

bool cmpr(pair<ll,ll> a, pair<ll,ll> b) {
    return a.first + a.second > b.first + b.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> r;
    vector<pair<ll,ll>> pos, neg;
    for (int i = 1; i <= n; i++) {
        ll x,y;
        cin >> x >> y;
        if (y >= 0) {
            pos.push_back({x,y});
        } else {
            neg.push_back({x,y});
        }
    }

    sort(pos.begin(), pos.end());

    bool ok = true;
    for (auto e : pos) {
        if (r < e.first) {
            ok = false;
            break;
        } else {
            r += e.second;
        }
    }

    sort(neg.begin(), neg.end(), cmpr);

    for (auto e : neg) {
        if (r < e.first) {
            ok = false;
            break;
        } else {
            r += e.second;
        }
        if (r < 0) {
            ok = false;
            break;
        }
    }

    puts(ok ? "YES" : "NO");


    return 0;
}
