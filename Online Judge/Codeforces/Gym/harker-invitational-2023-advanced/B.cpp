#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        pos[a] = i;
    }
    vector<int> ans(n + 1);
    int mid = (n + 1) / 2;
    int cur = 0;
    for (int i = mid + 1; i <= n; i++) {
        ans[pos[i]] = ++cur;
    }
    for (int i = 1; i <= mid; i++) {
        ans[pos[i]] = ++cur;
    }
    cout << n / 2 << '\n';
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
    
    return 0;
}