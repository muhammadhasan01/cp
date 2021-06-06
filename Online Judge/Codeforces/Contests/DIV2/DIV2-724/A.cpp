#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;

int n;
int a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    if (a[1] < 0) {
        cout << "NO" << '\n';
        return;
    }
    vector<int> ans;
    for (int i = 0; i <= a[n]; i++) {
        ans.emplace_back(i);
    }
    int len = ans.size();
    cout << "YES" << '\n';
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " \n"[i == len - 1];
    }
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