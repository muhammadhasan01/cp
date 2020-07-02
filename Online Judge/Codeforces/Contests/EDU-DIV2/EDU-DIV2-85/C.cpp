#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const long long INF = 1e16;

int tc;
int n;
int par[N];
long long a[N], b[N];

int fpar(int x) {
    return (par[x] == x ? x : par[x] = fpar(par[x]));
}

void merge(int u, int v) {
    int pu = fpar(u);
    int pv = fpar(v);
    if (pu == pv) return;
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
            par[i] = i;
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
        }
        for (int i = 1; i < n; i++) {
            if (b[i] >= a[i + 1]) {
                merge(i, i + 1);
            }
        }
        if (b[n] >= a[1]) {
            merge(n, 1);
        }
        int len = 0;
        long long sum = 0, minz = INF;
        b[0] = b[n];
        for (int i = 1; i <= n; i++) {
            int pi = fpar(i);
            if (pi == i) {
                ++len;
                sum += (a[i] - b[i - 1]);
                minz = min(minz, b[i - 1]);
            } else {
                minz = min(minz, a[i]);
            }
        }
        if (len == 1) {
            bool flag = true;
            a[n + 1] = a[1];
            for (int i = 1; i <= n; i++) {
                if (b[i] < a[i + 1]) {
                    flag = false;
                    break;
                }    
            }
            long long mini = *min_element(a + 1, a + 1 + n);
            if (flag) {
                cout << mini << '\n';
                continue;
            }
            cout << min(a[fpar(1)], sum + mini) << '\n';
        } else {
            cout << sum + minz << '\n';
        }
    }

    return 0;
}