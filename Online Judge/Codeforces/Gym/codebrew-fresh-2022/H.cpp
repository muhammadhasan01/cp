#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> ans;
    for (int rep = 0; rep < n; rep++) {
        int len = (int) a.size();
        int pos = -1;
        for (int i = len - 1; i >= 0; i--) {
            if (a[i] == i + 1) {
                pos = i + 1;
                break;
            }
        }
        if (pos == -1) {
            cout << "NO" << '\n';
            return 0;
        }
        ans.emplace_back(pos);
        a.erase(a.begin() + pos - 1);
    }
    reverse(ans.begin(), ans.end());
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
    
    return 0;
}