// author : donbasta
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define point pair<ll, ll>
#define x first
#define y second

int n;

ll dobelLuas(const vector<point>& p) {
    int sz = (int)p.size();
    ll ret = 0;
    for (int i = 0; i < sz; i++) {
        int ii = (i + 1) % sz;
        ret += (p[i].x * p[ii].y - p[i].y * p[ii].x);
    }
    return abs(ret);
}

void solve() {
    cin >> n;
    ll dobelAns = 0;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        vector<point> ve;
        for (int j = 0; j < p; j++) {
            ll xx, yy;
            cin >> xx >> yy;
            ve.emplace_back(xx, yy);
        }
        dobelAns += dobelLuas(ve);
    }
    cout << (dobelAns / 2) << '\n'; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}