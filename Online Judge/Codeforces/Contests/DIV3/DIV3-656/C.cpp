#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int tc;
int n, a[N];

bool can(int x) {
    int l = x + 1, r = n;
    int cur = 0;
    while (l <= r) {
        if (a[l] <= a[r]) {
            if (a[l] < cur) return false;
            cur = a[l];
            l++;
        } else {
            if (a[r] < cur) return false;
            cur = a[r];
            r--;
        }
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
        int l = 0, r = n - 1, ans = n - 1;
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