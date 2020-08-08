#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
long long S;
int a[N];

long long G(int k) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 1; i <= n; i++) {
        long long cur = (1LL) * a[i] + (1LL) * i * k;
        pq.emplace(cur);
    }
    long long ret = 0;
    for (int it = 0; it < k; it++) {
        ret += pq.top();
        pq.pop();
    }
    while (!pq.empty()) pq.pop();
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> S;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 0, r = n, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (G(mid) <= S) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << ' ' << G(ans) << '\n';

    return 0;
}