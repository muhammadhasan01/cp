#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    map<string, int> cars;
    vector<tuple<int, int, int>> v(n);
    for (int i = 0; i < n; i++) {
        string car; int p, q, k;
        cin >> car >> p >> q >> k;
        cars[car] = i;
        v[i] = make_tuple(p, q, k);
    }
    // price and current car
    map<string, pair<long long, int>> spies;
    for (int i = 0; i < m; i++) {
        int t; string spy; char tp;
        cin >> t >> spy >> tp;
        if (!spies.count(spy)) {
            spies[spy] = make_pair(0LL, -1);
        }
        auto [cst, cur] = spies[spy];
        if (tp == 'p') {
            string car;
            cin >> car;
            if (cst == -1) continue;
            if (cur == -1) {
                int id = cars[car];
                long long cost = get<1>(v[id]);
                spies[spy] = make_pair(cst + cost, id);
            } else {
                spies[spy] = make_pair(-1LL, -1);
            }
        } else if (tp == 'r') {
            long long d;
            cin >> d;
            if (cst == -1) continue;
            if (cur == -1) {
                spies[spy] = make_pair(-1LL, -1);
            } else {
                long long k = get<2>(v[cur]);
                spies[spy] = make_pair(cst + d * k, -1);
            }
        } else if (tp == 'a') {
            long long s;
            cin >> s;
            if (cst == -1) continue;
            if (cur == -1) {
                spies[spy] = make_pair(-1LL, -1);
            } else {
                long long p = get<0>(v[cur]);
                spies[spy] = make_pair(cst + (p * s + 99) / 100, cur);
            }
        }   
    }
    for (auto& [spy, val] : spies) {
        auto& [cst, cur] = val;
        cout << spy << ' ';
        if (cst == -1 || cur >= 0)
            cout << "INCONSISTENT" << '\n';
        else
            cout << cst << '\n'; 
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