#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int INF = 2e9;

int tc;
int n;
int a[N], pre[N], suf[N];
int ord[N];
pair<int, int> b[N];
int par[N], sz[N];

int fpar(int x) {
    if (par[x] == x) return x;
    return par[x] = fpar(par[x]);
}

void merge(int u, int v) {
    int pu = fpar(u);
    int pv = fpar(v);
    if (pu == pv) return;
    if (sz[pu] < sz[pv]) swap(pu, pv);
    sz[pu] += sz[pv];
    par[pv] = pu;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            par[i] = i, sz[i] = 1;
            b[i] = make_pair(a[i], i);
        }
        sort(b + 1, b + 1 + n);
        for (int i = 1; i <= n; i++) {
            a[b[i].second] = i;
            ord[i] = b[i].second;
        }
        for (int i = 1; i < n; i++) {
            if (ord[i + 1] > ord[i]) merge(i, i + 1);
        }
        for (int i = 1; i <= n; i++) {
            if (ord[i] == i) {
                pre[i] = 0;
            } else {
                for (int j = i; j <= n; j++) {
                    pre[j] = j;
                }
                break;
            }
        }
        suf[n + 1] = 0;
        for (int i = n; i >= 1; i--) {
            if (ord[i] == i) {
                suf[i] = 0;
            } else {
                for (int j = i; j >= 1; j--) {
                    suf[j] = n - j + 1;
                }
                break;
            }
        }
        int ans = INF;
        for (int i = 0; i <= n; i++) {
            int cur = pre[i];
            if (i == n) {
                ans = min(ans, cur);
                break;
            }
            int pp = fpar(i + 1);
            int k = sz[pp] - ((i + 1) - pp);
            cur += suf[min(n + 1, i + k + 1)];
            ans = min(ans, cur);
        }
        for (int i = n + 1; i >= 1; i--) {
            int cur = suf[i];
            if (i == 1) {
                ans = min(ans, cur);
                break;
            }
            int pp = fpar(i - 1);
            int k = sz[pp] - ((i - 1) - pp);
            k = sz[pp] - k + 1;
            cur += pre[max(0, i - k - 1)];
            ans = min(ans, cur);
        }
        cout << ans << '\n';
    }

    return 0;
}