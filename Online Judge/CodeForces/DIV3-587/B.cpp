#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n;
pair<int,int> a[N];
int ans[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n);
    long long res = 0;
    for (int i = n, j = 1; i >= 1; i--, j++) {
        res += (1LL) * (a[i].first * (j - 1) + 1);
        ans[j] = a[i].second;
    }
    cout << res << '\n';
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
