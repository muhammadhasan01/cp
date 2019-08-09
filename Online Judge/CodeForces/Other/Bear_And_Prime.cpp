#include<bits/stdc++.h>
using namespace std;

const int M = 1e7;
int n, m;
int cnt[M + 5], pre[M + 5], f[M + 5];
bitset<M + 5> prime;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    prime[1] = 1;
    for (int i = 2; i <= M; i++) {
        if (!prime[i]) {
            for (int j = i; j <= M; j += i) {
                if (j > i) prime[j] = 1;
                f[i] += cnt[j];
            }
        }
    }

    for (int i = 1; i <= M; i++) {
        pre[i] = pre[i - 1];
        if (!prime[i]) {
            pre[i] += f[i];
        }
    }

    cin >> m;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        r = min(r, M);
        l = min(l, M);
        cout << pre[r] - pre[l - 1] << "\n";
    }

    return 0;
}
