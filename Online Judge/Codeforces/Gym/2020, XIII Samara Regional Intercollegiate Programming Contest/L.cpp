#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
pair<int, int> p[N];

bool can(int k) {
    vector<int> val(n, -1);
    for (int i = 1; i <= k; i++) {
        val[p[i].second] = p[i].first;
    }
    for (int i = 0, j = 1; i < n; i++) {
        if (val[i] == -1) continue;
        if (val[i] < j) return false;
        ++j;
    }
    return true;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first;
        p[i].second = i - 1;
    }
    sort(p + 1, p + 1 + n, greater<pair<int, int>>());
    int l = 1, r = n, at = 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            l = mid + 1;
            at = mid;
        } else {
            r = mid - 1;
        }
    }
    long long ans = 0, sum = 0;
    for (int i = 1; i <= at; i++) {
        sum += (1LL) * p[i].first;
        long long cur = sum - (1LL) * i * (i + 1) / 2;
        ans = max(ans, cur);
    }
    cout << ans << '\n';

    return 0;
}