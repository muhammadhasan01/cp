#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& e : a) cin >> e;
    long long cur = 0;
    for (int i = 0; i < n; i += 2)
        cur += a[i];
    long long ans = cur;
    int pos = n - 1;
    for (int i = 0; i < n; i++) {
        cur -= a[pos];
        cur += a[(pos + n - 1) % n];
        pos = ((pos - 2) % n + n) % n;
        ans = max(ans, cur);
    }
    cout << ans << '\n';

    return 0;
}