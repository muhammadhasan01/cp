#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 3;
int tc, n;
long long s;
pair<int,int> p[N];

bool can(int x) {
    long long sum = 0;
    int cnt = 0;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (p[i].second < x) {
            sum += (1LL) * p[i].first;
        } else if (p[i].first >= x) {
            sum += (1LL) * p[i].first;
            ++cnt;
        } else {
            v.push_back(p[i].first);
        }
    }

    int need = max(0, (n + 1) / 2 - cnt);
    if (need > (int) v.size()) return false;
    for (int i = 0; i < (int) v.size(); i++) {
        if (i < (int) v.size() - need) sum += (1LL) * v[i];
        else sum += (1LL) * x;
    }
    return sum <= s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> s;
        for (int i = 1; i <= n; i++) {
            cin >> p[i].first >> p[i].second;
        }
        sort(p + 1, p + 1 + n);
        int l = 1, r = 1e9 + 100, ans = 1;
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
    }

    return 0;
}
