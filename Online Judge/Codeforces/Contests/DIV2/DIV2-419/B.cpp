#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n, k, q;
int cnt[N], pre[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        cnt[l]++;
        cnt[r + 1]--;
    }
    for (int i = 1; i < N; i++) {
        cnt[i] += cnt[i - 1];
        pre[i] = pre[i - 1];
        if (cnt[i] >= k) {
            pre[i]++;
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << "\n";
    }

    return 0;
}