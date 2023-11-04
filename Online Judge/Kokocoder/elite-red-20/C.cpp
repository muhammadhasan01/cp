#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.length();
    vector<int> pos;
    pos.emplace_back(0);
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            pos.emplace_back(i + 1);
        }
    }
    pos.emplace_back(n + 1);
    int len = pos.size();
    if (k == 0) {
        long long ans = 0;
        for (int i = 1; i < len; i++) {
            int cur = pos[i] - pos[i - 1] - 1;
            ans += 1LL * cur * (cur + 1) / 2;
        }
        cout << ans << '\n';
        return 0;
    }
    long long ans = 0;
    for (int l = 1, r = k; r + 1 < len; l++, r++) {
        int L = pos[l] - pos[l - 1];
        int R = pos[r + 1] - pos[r];
        ans += 1LL * L * R;
    }
    cout << ans << '\n';
    
    return 0;
}