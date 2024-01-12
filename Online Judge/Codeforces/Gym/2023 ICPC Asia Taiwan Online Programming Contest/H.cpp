#include <bits/stdc++.h>

using namespace std;

const long long K = 62;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long n, k;
    cin >> n >> k;

    auto getCnt = [&](long long node) -> long long {
        long long l = node, r = min(n, node);
        long long cnt = 0;
        while (l <= n) {
            cnt += r - l + 1;
            l = l * 2;
            r = min(n, r * 2 + 1);
        }
        return cnt;
    };

    long long U = min(n, (1LL << min(K, k)) - 1LL);
    long long L = 0;
    long long steps = (1LL << K);
    while (steps > 0) {
        long long cnt = getCnt(L + steps);
        if (n - cnt + 1 < k) {
            L += steps;
        }
        steps /= 2;
    }
    cout << U - L << '\n';
    
    return 0;
}