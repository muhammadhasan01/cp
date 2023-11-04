#include <bits/stdc++.h>

using namespace std;

const int INF = 2e5;
const int N = 1e5 + 5;

vector<int> divisors[N];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    auto can = [&](int dif) -> bool {
        vector<int> freq(m + 1);
        int cnt = 0;

        auto add = [&](int x) -> void {
            for (int div : divisors[x]) {
                if (div > m) {
                    break;
                }
                if (++freq[div] == 1) {
                    ++cnt;
                }
            }
        };

        auto remove = [&](int x) -> void {
            for (int div : divisors[x]) {
                if (div > m) {
                    break;
                }
                if (--freq[div] == 0) {
                    --cnt;
                }
            }
        };

        for (int l = 0, r = -1; l < n; l++) {
            while (r + 1 < n && a[r + 1] - a[l] <= dif) {
                add(a[++r]);
            }
            if (cnt == m) {
                return true;
            }
            remove(a[l]);
        }
        return cnt == m;
    };

    int l = 0, r = INF, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            divisors[j].emplace_back(i);
        }
    }
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}