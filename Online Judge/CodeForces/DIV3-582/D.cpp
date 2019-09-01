#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, k;
int a[N];
int f[N];
priority_queue<int> pq[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    int maks = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        maks = max(maks, x);
        int j = 0;
        while (1) {
            pq[x].push(j);
            f[x] += j;
            if (pq[x].size() == k) {
                f[x] -= pq[x].top();
                pq[x].pop();
            }
            if (x == 0) break;
            x /= 2;
            j++;
        }
    }
    int ans = 1e9;
    for (int i = 0; i <= maks; i++) {
        if (pq[i].size() == k) {
            ans = min(ans, f[i]);
        }
    }
    cout << ans << '\n';

    return 0;
}
