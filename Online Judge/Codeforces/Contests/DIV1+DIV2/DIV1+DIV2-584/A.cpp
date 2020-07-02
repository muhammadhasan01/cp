#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int n;
int a[N];
bitset<N> vis;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) ans++;
        for (int j = i + 1; j <= n; j++) {
            if (a[j] % a[i] == 0) vis[j] = 1;
        }
    }
    cout << ans << '\n';

    return 0;
}
