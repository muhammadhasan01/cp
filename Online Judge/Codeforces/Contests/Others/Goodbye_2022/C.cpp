#include <bits/stdc++.h>

using namespace std;

const int P = 205;

bitset<P> notPrime;
vector<int> primes;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    set<long long> S;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        S.emplace(a[i]);
    }
    if ((int) S.size() != n) {
        cout << "NO" << '\n';
        return;
    }
    for (int p : primes) {
        vector<int> cnt(p);
        for (long long x : a) {
            cnt[x % p]++;
        }
        if (*min_element(cnt.begin(), cnt.end()) >= 2) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    notPrime[1] = 1;
    for (int i = 2; i < P; i++) {
        if (notPrime[i]) {
            continue;
        }
        primes.emplace_back(i);
        for (int j = i + i; j < P; j += i) {
            notPrime[j] = 1;
        }
    }
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}