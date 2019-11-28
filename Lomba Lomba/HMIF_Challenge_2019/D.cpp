#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
int n;
int a[N], le[N], ri[N];
pair<int, int> p[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = {a[i], i};
        le[i] = i - 1;
        ri[i] = i + 1;
    }

    sort(p + 1, p + 1 + n);

    int l = 1, r = n;
    long long ans = 0;
    for (int i = 1; i <= n - 2; i++) {
        int cur = p[i].second;

        if (cur == l) {
            l = ri[l];
            ans += (1LL) * p[i].first;
            continue;
        }

        if (cur == r) {
            r = le[r];
            ans += (1LL) * p[i].first;
            continue;
        }

        ans += min(a[le[cur]], a[ri[cur]]);
        ri[le[cur]] = ri[cur];
        le[ri[cur]] = le[cur];
    }

    cout << ans << '\n';

    return 0;
}
