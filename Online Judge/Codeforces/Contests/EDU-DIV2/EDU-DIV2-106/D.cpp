#include <bits/stdc++.h>

using namespace std;

const int N = 2e7 + 5;

int cprime[N];

void solve() {
    int c, d, x;
    cin >> c >> d >> x;
    long long ans = 0;
    auto check = [&](int num) -> void {
        if ((num + d) % c != 0) {
            return;
        }
        int res = (num + d) / c;
        ans += (1LL << cprime[res]);
    };
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            check(i);
            if (i * i != x) {
                check(x / i);
            }
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for (int i = 2; i < N; i++) {
        if (cprime[i] > 0) {
            continue;
        }
        for (int j = i; j < N; j += i) {
            cprime[j]++;
        }
    }

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}