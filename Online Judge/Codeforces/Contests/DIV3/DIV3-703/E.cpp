#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
pair<long long, int> a[N];
long long pre[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i].first;
    }
    int last = n;
    for (int i = n - 1; i >= 1; i--) {
        if (a[i + 1].first > pre[i]) break;
        last = i;
    }
    vector<int> ans;
    for (int i = n; i >= last; i--) {
        ans.emplace_back(a[i].second);
    }
    sort(ans.begin(), ans.end());
    int len = ans.size();
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