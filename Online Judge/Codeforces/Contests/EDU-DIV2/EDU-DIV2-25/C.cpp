#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n;
long long k;
long long a[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int cur = 1, ans = 0;
    while (cur <= n) {
        if (2 * k >= a[cur]) {
            k = max(k, a[cur]);
            ++cur;
            continue;
        }
        k *= 2;
        ++ans;
    }
    cout << ans << '\n';

    return 0;
}