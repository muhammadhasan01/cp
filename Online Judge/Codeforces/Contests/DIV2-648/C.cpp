#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

int n;
int a[N], b[N], f[N];
int ord[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ord[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i] = ord[b[i]];
        b[n + i] = b[i];
    }
    for (int i = 1; i <= n; i++) {
        int res = b[i] - i;
        if (res < 0) res += n;
        f[res]++;
    }
    int ans = 0;
    for (int i = 0; i <= 2 * n; i++) {
        ans = max(ans, f[i]);
    }
    cout << ans << '\n';
  
    return 0;
}