#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

bool not_prime[N];
vector<int> primes;

void solve() {
    int d;
    cin >> d;
    int p = *lower_bound(primes.begin(), primes.end(), 1 + d);
    int q = *lower_bound(primes.begin(), primes.end(), p + d);
    cout << 1LL * p * q << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i < N; i++) {
        if (not_prime[i]) {
            continue;
        }
        primes.emplace_back(i);
        for (int j = i + i; j < N; j += i) {
            not_prime[j] = true;
        }
    }
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}