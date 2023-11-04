#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<bool> vis(n + 1);
    vector<int> ans;
    for (int i = 2; i <= n; i++) {
        if (vis[i]) {
            continue;
        }
        int x = i;
        while (x <= n) {
            ans.emplace_back(x);
            x = (x * i);
        }
        for (int j = i; j <= n; j += i) {
            vis[j] = true;
        }
    }
    int len = ans.size();
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " \n"[i == len - 1];
    }
    
    return 0;
}