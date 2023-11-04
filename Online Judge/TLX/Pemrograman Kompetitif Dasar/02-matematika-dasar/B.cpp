#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

bitset<N> not_prime;
vector<int> primes;

void solve() {
    int k;
    cin >> k;
    cout << primes[k - 1] << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    not_prime[1] = 1;
    for (int i = 2; i < N; i++) {
        if (not_prime[i] == 1) {
            continue;
        }
        primes.emplace_back(i);
        for (int j = i + i; j < N; j += i) {
            not_prime[j] = 1;
        }
    }
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}