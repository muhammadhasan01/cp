#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long t, d;
        cin >> t >> d;
        ans = max(ans, t); ans += d;
    }
    cout << ans << '\n';

    return 0;
}