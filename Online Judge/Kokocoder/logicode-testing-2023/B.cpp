#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, q;
long long a[N];
long long pre[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, greater<long long>());
    for (int i = 1; i <= n; i++) {
        pre[i] += a[i] + pre[i - 1];
    }
    while (q--) {
        long long val;
        cin >> val;
        int l = 1, r = n, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (pre[mid] > val) {
                r = mid - 1;
                at = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << at << '\n';
    }
    
    return 0;
}