#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> p(n);
    int maxL = -INF, minR = INF;
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
        maxL = max(maxL, p[i].first);
        minR = min(minR, p[i].second);
    }
    sort(p.begin(), p.end());
    vector<int> pre(n);
    for (int i = 0; i < n; i++) {
        pre[i] = p[i].second;
        if (i > 0) {
            pre[i] = max(pre[i], pre[i - 1]);
        }
    }
    
    auto can = [&](int x, int y) -> bool {
        if (minR < x || maxL > y) {
            return false;
        }
        int l = 0, r = n - 1, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (p[mid].first < x) {
                at = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (at != -1 && pre[at] > y) {
            return false;
        }
        return true;
    };

    vector<int> cnt(m + 5);
    for (int i = 1; i <= m; i++) {
        int l = 1, r = i, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (can(mid, i)) {
                l = mid + 1;
                at = mid;
            } else {
                r = mid - 1;
            }
        }
        if (at == -1) {
            continue;
        }
        int len = i - at + 1;
        cnt[len]++;
        cnt[i + 1]--;
    }
    for (int i = 1; i <= m; i++) {
        cnt[i] += cnt[i - 1];
        cout << cnt[i] << " \n"[i == m];
    }
    
    return 0;
}