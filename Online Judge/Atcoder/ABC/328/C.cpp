#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<char> s(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + (s[i] == s[i + 1]);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << pre[r - 1] - pre[l - 1] << '\n';
    }
    
    return 0;
}