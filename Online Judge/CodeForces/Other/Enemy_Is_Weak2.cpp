#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n;
int a[N], b[N], c[N], cnt = 1;
pair<int,int> p[N];
long long le[N], ri[N], ans;

void add(int *arr, int x) {
    for ( ; x <= n; x += x & -x) {
        arr[x]++;
    }
}

int qr(int *arr, int x) {
    int ret = 0;
    for ( ; x > 0; x -= x & -x) {
        ret += arr[x];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = {a[i], i};
    }
    sort(p + 1, p  + 1 + n);
    for (int i = 1; i <= n; i++) {
        a[p[i].second] = cnt;
        while (i < n && p[i + 1].first == p[i].first) {
            a[p[i + 1].second] = cnt;
            i++;
        }
        cnt++;
    }
    for (int i = 1; i <= n; i++) {
        le[i] = qr(b, cnt - a[i] - 1);
        add(b, cnt - a[i]);
    }
    for (int i = n; i >= 1; i--) {
        ri[i] = qr(c, a[i] - 1);
        add(c, a[i]);
    }
    for (int i = 1; i <= n; i++) ans += le[i] * ri[i];
    cout << ans << '\n';

    return 0;
}
