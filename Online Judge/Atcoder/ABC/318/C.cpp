#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    long long d, p;
    cin >> n >> d >> p;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    long long ans = 0;
    long long cur = 0;
    for (int i = 0, cnt = 1; i < n; i++) {
        cur += a[i];
        if (cnt == d) {
            ans += min(cur, p);
            cur = 0;
            cnt = 1;
        } else {
            ++cnt;
        }
    }
    ans += min(cur, p);
    cout << ans << '\n';
    
    return 0;
}