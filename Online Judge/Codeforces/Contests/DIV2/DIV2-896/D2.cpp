#include <bits/stdc++.h>

using namespace std;

const int K = 40;

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
    vector<int> L(K), R(K);
    vector<int> cl(K), cr(K);
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
        L[l]++, R[r]++;
        if (r - l == 1) {
            cl[l]++;
        }
        if (l - r == 1) {
            cr[r]++;
        }
    }
    for (int x = 0; x + 1 < K; x++) {
        if (L[x] < 0 || R[x] < 0) {
            cout << "No" << '\n';
            return;
        }
        int dif = L[x] - R[x];
        if (abs(dif) & 1) {
            cout << "No" << '\n';
            return;
        }
        int add = abs(dif) / 2;
        if (dif > 0) {
            if (add > cl[x]) {
                cout << "No" << '\n';
                return;
            }
            R[x + 1] -= add;
        } else {
            if (add > cr[x]) {
                cout << "No" << '\n';
                return;
            }
            L[x + 1] -= add;
        }
    }
    cout << "Yes" << '\n';
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