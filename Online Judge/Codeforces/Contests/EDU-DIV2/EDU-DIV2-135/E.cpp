#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> difs(n);
    vector<long long> sums(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        difs[i] = b[i] - a[i];
        sums[0] += a[i];
    }
    sort(difs.begin(), difs.end(), greater<int>());
    for (int i = 1; i <= n; i++) {
        sums[i] = sums[i - 1] + difs[i - 1];
    }
    int maxPos = max_element(sums.begin(), sums.end()) - sums.begin();
    int m;
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        int c1, c2;
        int g = gcd(x, y, c1, c2);
        if (n % g != 0) {
            cout << -1 << '\n';
            continue;
        }
        long long smallestY = -1, largestY = -1;
        {
            long long k = x / g;
            smallestY = ((1LL * c2 * (n / g)) % k + k) % k;
        }
        {
            long long k = y / g;
            long long smallestX = ((1LL * c1 * (n / g)) % k + k) % k;
            largestY = (n - x * smallestX) / y;
        }
        long long smallestTake = smallestY * y;
        if (smallestTake > n) {
            cout << -1 << '\n';
            continue;
        }
        long long largestTake = largestY * y;
        if (smallestTake >= maxPos) {
            cout << sums[smallestTake] << '\n';
            continue;
        }
        if (largestTake <= maxPos) {
            cout << sums[largestTake] << '\n';
            continue;
        }
        long long jump = 1LL * (x / g) * y;
        long long nearestTake = ((maxPos - smallestTake) / jump) * jump + smallestTake;
        long long ans = sums[nearestTake];
        if (nearestTake + jump <= largestTake) {
            ans = max(ans, sums[nearestTake + jump]);
        }
        cout << ans << '\n';
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}