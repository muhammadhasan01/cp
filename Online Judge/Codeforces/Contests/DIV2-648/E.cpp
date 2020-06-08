#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int n;
long long a[N];
long long ans;
int cnt[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n <= 3) {
        for (int i = 1; i <= n; i++) {
            ans = (ans | a[i]);
        }
        cout << ans << '\n';
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                long long res = (a[i] | a[j]);
                res = (res | a[k]);
                ans = max(ans, res);
            }
        }
    }
    cout << ans << '\n';

    return 0;
}