#include <bits/stdc++.h>

using namespace std;

long long n, k;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    if (k >= 200000) {
        cout << -1 << '\n';
        return 0;
    }
    vector<long long> div;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            div.emplace_back(i);
            if (i * i != n) div.emplace_back(n / i);
        }
    }
    sort(div.begin(), div.end(), greater<long long>());
    long long x = k * (k + 1) / 2;
    for (auto m : div) {
        if (n / m >= x) {
            long long dif = n / m - x;
            for (long long i = 1; i <= k; i++) {
                long long res = i;
                if (i == k) res += dif;
                cout << res * m << (i == k ? '\n' : ' ');
            }
            return 0;
        }
    }
    cout << -1 << '\n';

    return 0;
}