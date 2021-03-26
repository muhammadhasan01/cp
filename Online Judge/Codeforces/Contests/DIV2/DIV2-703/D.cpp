#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int N = 2e5 + 5;

int n, k;
int a[N];
int pre[N];

bool can(int x) {
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + (a[i] >= x ? 1 : -1);
    }
    int sum = pre[k];
    int maxi = -INF;
    int mini = 0;
    for (int i = k; i <= n; i++) {
        maxi = max(maxi, sum - mini);
        mini = min(mini, pre[i - k + 1]);
        if (i + 1 <= n) sum += (a[i + 1] >= x ? 1 : -1);
    }
    return maxi >= 1;
} 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 1, r = n, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            l = mid + 1;
            ans = mid; 
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';

    return 0;
}