#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& e : v) cin >> e;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        ans.emplace_back(v[i]);
        if (i + 1 < n && __gcd(v[i], v[i + 1]) > 1) {
            ans.emplace_back(1);
        }
    }
    int len = ans.size();
    cout << len - n << '\n';
    for (int i = 0; i < len; i++) {
        cout << ans[i] << (i == len - 1 ? '\n' : ' ');
    }

    return 0;
}