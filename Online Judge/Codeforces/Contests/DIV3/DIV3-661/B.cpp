#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int tc;
int n;
int a[N], b[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int mini_a = a[1], mini_b = b[1];
    for (int i = 1; i <= n; i++) {
        mini_a = min(mini_a, a[i]);
        mini_b = min(mini_b, b[i]);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long dif_a = a[i] - mini_a;
        long long dif_b = b[i] - mini_b;
        ans += max(dif_a, dif_b);
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--)
        solve();

    return 0;
}