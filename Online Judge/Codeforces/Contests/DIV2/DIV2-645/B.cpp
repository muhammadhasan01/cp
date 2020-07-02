#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int tc;
int n;
int a[N];

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
        int ans = 1;
        for (int i = n; i >= 1; i--) {
            if (i >= a[i]) {
                ans = i + 1;
                break;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}