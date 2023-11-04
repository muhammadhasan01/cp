#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 5;

int pp[N];

void solve() {
    int x, y;
    cin >> x >> y;
    int dif = y - x;
    if (dif == 1) {
        cout << -1 << '\n';
        return;
    }
    vector<int> primes;
    int num = dif;
    while (num > 1) {
        int p = pp[num];
        while (num % p == 0) {
            num /= p;
        }
        primes.emplace_back(p);
    }
    int ans = INT_MAX;
    for (int p : primes) {
        int cur = (p + x - 1) / p;
        int val = cur * p;
        ans = min(ans, val - x);
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i < N; i++) {
        if (pp[i] > 0) {
            continue;
        }
        for (int j = i; j < N; j += i) {
            pp[j] = i;
        }
    }
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}