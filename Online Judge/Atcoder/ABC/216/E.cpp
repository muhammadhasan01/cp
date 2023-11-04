#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto F = [&](long long x) -> long long {
        return x * (x + 1) / 2;
    };

    sort(a.rbegin(), a.rend());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == a[i + 1]) {
            continue;
        }
        long long l = i + 1;
        long long d = a[i] - a[i + 1];
        if (k >= l * d) {
            ans += l * (F(a[i]) - F(a[i + 1]));
            k -= l * d;
            continue;            
        }
        long long t = k / l;
        long long r = k % l;
        ans += l * (F(a[i]) - F(a[i] - t)) + r * (a[i] - t);
        break;
    }
    cout << ans << '\n';
    
    return 0;
}