#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n;
int a[N], b[N];
int pos[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vector<int> suf(n + 3, n + 3);
    for (int i = n; i >= 1; i--) {
        suf[i] = min(pos[b[i]], suf[i + 1]);
    }
    int ans = 0;
    for (int i = 1; i <= n - 1; i++) {
        if (pos[b[i]] > suf[i + 1]) ans++;
    }
    cout << ans << '\n';

    return 0;
}
