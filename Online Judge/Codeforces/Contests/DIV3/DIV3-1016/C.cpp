#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

bool notPrime[N];
vector<int> primes;

bool isPrime(int n) {
    if (n == 1) {
        return false;
    }
    for (int p : primes) {
        if (1LL * p * p > 1LL * n) {
            break;
        }
        if (n % p == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int x, k;
    cin >> x >> k;
    if (x != 1 && k > 1) {
        cout << "NO" << '\n';
        return;
    }
    if (k == 1) {
        cout << (isPrime(x) ? "YES" : "NO") << '\n';
        return;
    }
    int res = 0;
    for (int rep = 0; rep < k; rep++) {
        res = 10 * res + 1;
    }
    cout << (isPrime(res) ? "YES" : "NO") << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    notPrime[1] = true;
    for (int i = 2; i < N; i++) {
        if (notPrime[i]) {
            continue;
        }
        primes.emplace_back(i);
        for (int j = i + i; j < N; j += i) {
            notPrime[j] = true;
        }
    }
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}