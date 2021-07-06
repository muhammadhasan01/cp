#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<long long> t(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> w[i];
    }
    long long x = t[0];
    priority_queue<long long, vector<long long>, greater<long long>> higher;
    priority_queue<pair<long long, int>> lower;
    for (int i = 1; i < n; i++) {
        if (t[i] > x) {
            higher.emplace(w[i] - t[i] + 1);
        } else {
            lower.emplace(t[i], i);
        }
    }
    int ans = (int) higher.size() + 1;
    while (!higher.empty()) {
        long long dif = higher.top();
        higher.pop();
        if (dif > x) {
            break;
        }
        x -= dif;
        while (!lower.empty()) {
            auto [val, i] = lower.top();
            if (val <= x) {
                break;
            }
            lower.pop();
            higher.emplace(w[i] - t[i] + 1);
        }
        ans = min(ans, (int) higher.size() + 1);
    }
    cout << ans << '\n';

    return 0;
}