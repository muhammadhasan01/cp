#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string str;
    cin >> str;
    long long k;
    cin >> k;
    vector<pair<int, int>> P;
    int X = -1, Y = -1;
    {
        int x = 0, y = 0;
        P.emplace_back(x, y);
        for (char cc : str) {
            if (cc == 'R') {
                x++;
            } else if (cc == 'L') {
                x--;
            } else if (cc == 'U') {
                y--;
            } else if (cc == 'D') {
                y++;
            }
            P.emplace_back(x, y);
        }
        X = x;
        Y = y;
    }
    sort(P.begin(), P.end());
    P.resize(unique(P.begin(), P.end()) - P.begin());
    if (X == 0 && Y == 0) {
        cout << (int) P.size() << '\n';
        return 0;
    }
    if (X == 0) {
        for (auto& [x, y] : P) {
            swap(x, y);
        }
        swap(X, Y);
    }
    if (X < 0) {
        for (auto& [x, _] : P) {
            x = -x;
        }
        X = -X;
    }
    int n = (int) P.size();
    map<pair<long long, long long>, vector<long long>> mp;
    for (int i = n - 1; i >= 0; i--) {
        auto [x, y] = P[i];
        long long s = (x % X + X) % X;
        long long dif = (x - s) / X;
        long long t = y - 1LL * dif * Y;
        mp[{s, t}].emplace_back(dif);
    }
    long long ans = 0;
    for (auto& [_, v] : mp) {
        sort(v.begin(), v.end());
        for (int i = 1; i < (int) v.size(); i++) {
            ans += min(k, v[i] - v[i - 1]);
        }
        ans += k;
    }
    cout << ans << '\n';
    
    return 0;
}