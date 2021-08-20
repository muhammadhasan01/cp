#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> ans(n + 1);
    int len = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            ans[len++] = n + 1;
            for (int j = i; j < n; j++) {
                ans[len++] = j + 1;
            }
            break;
        } else {
            ans[len++] = i + 1;
        }
    }
    if (len < n + 1) {
        ans[len++] = n + 1;
    }
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " \n"[i == len - 1];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}