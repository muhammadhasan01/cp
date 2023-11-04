#include <bits/stdc++.h>

using namespace std;

const int K = 35;

map<long long, pair<int, int>> mp;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % n != 0) {
        cout << "No" << '\n';
        return;
    }
    long long target = sum / n;
    vector<int> L, R;
    for (int i = 0; i < n; i++) {
        long long dif = target - a[i];
        if (dif == 0) {
            continue;
        }
        if (!mp.count(dif)) {
            cout << "No" << '\n';
            return;
        }
        auto [l, r] = mp[dif];
        L.emplace_back(l);
        R.emplace_back(r);
    }
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    cout << (L == R ? "Yes" : "No") << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            if (i == j) {
                continue;
            }
            long long x = (1LL << i);
            long long y = (1LL << j);
            mp[x - y] = {i, j};
        }
    }
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}