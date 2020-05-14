#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int tc;
int n;
int a[N], ans[N];

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
        sort(a + 1, a + 1 + n);
        for (int i = n, l = 1, r = n; i >= 1; i--) {
            if ((n - i) % 2 == 0) {
                ans[i] = a[l++];
            } else {
                ans[i] = a[r--];
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << (i == n ? '\n' : ' ');
        }
    }

    return 0;
}