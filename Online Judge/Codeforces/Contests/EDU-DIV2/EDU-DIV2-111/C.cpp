#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];
bool good[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> v(4);
    for (int i = 3; i <= n; i++) {
        good[i] = true;
        if (a[i] >= a[i - 1] && a[i - 1] >= a[i - 2]) {
            good[i] = false;
            continue;
        }
        if (a[i] <= a[i - 1] && a[i - 1] <= a[i - 2]) {
            good[i] = false;
            continue;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (i <= 2) {
            ans += i;
            continue;
        }
        ans += 2;
        if (good[i]) {
            ans++;
            if (i > 3 && good[i - 1]) {
                if (a[i] >= a[i - 1] && a[i - 1] >= a[i - 3]) {
                    continue;
                }
                if (a[i] <= a[i - 1] && a[i - 1] <= a[i - 3]) {
                    continue;
                }
                if (a[i] <= a[i - 2] && a[i - 2] <= a[i - 3]) {
                    continue;
                }
                if (a[i] >= a[i - 2] && a[i - 2] >= a[i - 3]) {
                    continue;
                }
                ans++;
            }
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}