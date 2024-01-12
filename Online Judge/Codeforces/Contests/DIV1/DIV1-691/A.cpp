#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long G = 0;
    for (int i = 1; i < n; i++) {
        G = __gcd(G, a[i] - a[0]);
    }
    for (int i = 0; i < m; i++) {
        long long x;
        cin >> x;
        cout << __gcd(G, a[0] + x) << " \n"[i == m - 1];
    }

    return 0;
}