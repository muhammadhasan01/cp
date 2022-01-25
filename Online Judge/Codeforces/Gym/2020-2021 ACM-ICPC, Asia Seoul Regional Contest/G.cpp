#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    long long d;
    cin >> n >> d;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    long long ans = INF;
    for (long long x : {1LL, -1LL}) {
        vector<long long> w(n);
        for (int i = 0; i < n; i++) {
            w[i] = v[i] + x * d * i;
        }
        long long dif = *max_element(w.begin(), w.end()) - *min_element(w.begin(), w.end());
        ans = min(ans, dif);
    }
    cout << ans / 2 << "." << (ans % 2 ? 5 : 0) << '\n';

    return 0;
}