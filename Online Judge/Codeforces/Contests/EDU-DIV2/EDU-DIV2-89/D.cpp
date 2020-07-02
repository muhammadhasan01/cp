#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
const int M = 1e7 + 5;

int n;
int a[N], b[N];
int len[N], id[N];
int ans[N][2];
int ord[M];
bitset<M> notPrime;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
        if (ord[a[i]]) continue;
        ord[a[i]] = ++cnt;
        id[cnt] = a[i];
    }
    int lastPrime;
    for (int i = 2; i < M; i++) {
        if (!notPrime[i]) {
            lastPrime = i;
            for (int j = i + i; j < M; j += i) {
                notPrime[j] = true;
                if (ord[j] == 0) continue;
                if (len[ord[j]] == 2) continue;
                ans[ord[j]][len[ord[j]]] = i;
                ++len[ord[j]];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        a[i] = ord[b[i]];
    }
    for (int i = 1; i <= n; i++) {
        if (len[a[i]] < 2) {
            cout << -1;
        } else {
            cout << ans[a[i]][0];
        }
        cout << (i == n ? '\n' : ' ');
    }
    for (int i = 1; i <= n; i++) {
        if (len[a[i]] < 2) {
            cout << -1;
        } else {
            int res = id[a[i]];
            while (res % ans[a[i]][0] == 0) res /= ans[a[i]][0]; 
            cout << res;
        }
        cout << (i == n ? '\n' : ' ');
    }

    return 0;
}