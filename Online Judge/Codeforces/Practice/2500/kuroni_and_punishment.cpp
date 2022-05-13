#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int K = 20;

bool not_prime[N];

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> primes;
    for (int i = 2; i < N; i++) {
        if (not_prime[i]) {
            continue;
        }
        primes.emplace_back(i);
        for (int j = i + i; j < N; j += i) {
            not_prime[j] = true;
        }
    }
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<long long> candidates;
    auto add_candidate = [&](long long x) -> void {
        for (int p : primes) {
            if (p > x) {
                break;
            }
            candidates.emplace(p);
            while (x % p == 0) {
                x /= p;
            }
        }
        if (x > 1) {
            candidates.emplace(x);
        }
    };
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    shuffle(order.begin(), order.end(), rng32);
    for (int i = 0; i < min(n, K); i++) {
        int pos = order[i];
        for (long long x : {a[pos] - 1, a[pos], a[pos] + 1}) {
            add_candidate(x);
        }
    }
    long long ans = n;
    for (long long candidate : candidates) {
        long long ret = 0;
        for (int i = 0; i < n; i++) {
            long long cur = 0;
            if (a[i] < candidate) {
                cur = candidate - a[i];
            } else {
                long long rem = a[i] % candidate;
                cur = min(rem, candidate - rem);
            }
            ret += cur;
            if (ret > ans) {
                break;
            }
        }
        ans = min(ans, ret);
    }
    cout << ans << '\n';

    return 0;
}