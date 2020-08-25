#include <bits/stdc++.h>

using namespace std;

long long n, k;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    vector<long long> div;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            div.emplace_back(i);
            if (i * i != n) div.emplace_back(n / i);
        }
    }
    sort(div.begin(), div.end());
    int len = div.size();
    if (len >= k) {
        cout << div[k - 1] << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}