#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

bitset<N> notPrime;
vector<int> primes;

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    if (a > b) {
        swap(a, b);
    }
    if (k == 1) {
        if (a == b) {
            cout << "NO" << '\n';
            return;
        }
        cout << (b % a == 0 ? "YES" : "NO") << '\n';
        return;
    }

    auto getCnt = [&](int x) -> int {
        int cnt = 0;
        for (int p : primes) {
            if (1LL * p * p > x) {
                break;
            }
            while (x % p == 0) {
                x /= p;
                cnt++;
            }
        }
        if (x > 1) {
            ++cnt;
        }
        return cnt;
    };

    cout << (getCnt(a) + getCnt(b) >= k ? "YES" : "NO") << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i < N; i++) {
        if (notPrime[i] == 1) {
            continue;
        }
        primes.emplace_back(i);
        for (int j = i + i; j < N; j += i) {
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