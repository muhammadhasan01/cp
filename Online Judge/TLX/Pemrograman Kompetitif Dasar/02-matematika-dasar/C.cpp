#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    long long res = 1;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        res = res * (x / __gcd(res, x));
    }
    cout << res << '\n';
    
    return 0;
}