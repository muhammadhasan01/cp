#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, r;
int a[N];
long long b[N], c[N];
map<long long, int> m1, m2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] % r == 0) {
            b[i] = m1[a[i] / r];
        }
        m1[a[i]]++;
    }
    for (int i = n; i >= 1; i--) {
        c[i] = m2[a[i] * r];
        m2[a[i]]++;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (c[i] * b[i]);
    }
    cout << ans << '\n';

    return 0;
}
