#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int tc;
int n;
long long a[N], b[N];

bool can(int x) {
    for (int i = 1; i <= n; i++) {
        b[i] = a[i];
    }
    long long addz = (1LL << x) - 1;
    b[n] += addz;
    for (int i = n - 1; i >= 1; i--) {
        if (b[i] > b[i + 1]) return false;
        b[i] = min(b[i + 1], b[i] + addz);
    }
    return true;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        int l = 0, r = 60, ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (can(mid)) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}