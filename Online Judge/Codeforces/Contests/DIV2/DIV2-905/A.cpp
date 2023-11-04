#include <bits/stdc++.h>

using namespace std;

const int K = 26;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(K);
    for (char cc : s) {
        cnt[(int) (cc - 'a')]++;
    }
    for (int i = 0; i < K && k > 0; i++) {
        if (cnt[i] & 1) {
            cnt[i]--;
            k--;
        }
    }
    for (int i = 0; i < K && k > 0; i++) {
        if (cnt[i] > 0) {
            assert(cnt[i] % 2 == 0);
            int take = min(cnt[i], k);
            cnt[i] -= take;
            k -= take;
        }
    }
    int odd = 0;
    for (int i = 0; i < K; i++) {
        if (cnt[i] & 1) {
            ++odd;
        }
    }
    cout << (odd <= 1 ? "YES" : "NO") << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}