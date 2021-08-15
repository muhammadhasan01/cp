#include <bits/stdc++.h>

using namespace std;

const int K = 25;

int n;
int a[K + 5];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    long long ans = 0;
    for (int i = 1, j = K; i <= n; i++) {
        if (a[i] <= K) {
            continue;
        }
        ans += (a[i] - j);
        j = a[i];
    }
    cout << ans << '\n';

    return 0;
}