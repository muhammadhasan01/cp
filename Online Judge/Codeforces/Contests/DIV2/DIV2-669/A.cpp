#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5; 

int tc;
int n;
int a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> ans;
    for (int i = 1; i <= n; i += 2) {
        if (a[i] == a[i + 1]) {
            ans.emplace_back(a[i]); ans.emplace_back(a[i + 1]);
        } else {
            ans.emplace_back(0);
        }
    }
    int len = ans.size();
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << ans[i] << (i == len - 1 ? '\n' : ' ');
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}