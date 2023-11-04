#include <bits/stdc++.h>

using namespace std;

const long long INF = 2e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, b, k;
    cin >> n >> b >> k;
    vector<int> m(k), s(k), p(k);
    for (int i = 0; i < k; i++) {
        cin >> m[i] >> s[i] >> p[i];
    }
    vector<int> ord(k);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int& i, int& j) {
        return s[i] + p[i] < s[j] + p[j];
    });

    auto can = [&](long long t) -> bool {
        int curb = b;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int it = 0; it < k; it++) {
            int i = ord[it];
            if (s[i] + p[i] > t) {
                break;
            }
            int have = min(1LL * m[i], (t - p[i]) / s[i]);
            curb -= have;
            pq.emplace(have);
            if ((int) pq.size() > n) {
                curb += pq.top();
                pq.pop();
            }
            if (curb <= 0) {
                return true;
            }
        }
        return curb <= 0;
    };

    long long l = 1, r = INF, ans = -1;
    while (l <= r) {
        long long mid = l + (r - l) / 2L;
        if (can(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
    
    return 0;
}