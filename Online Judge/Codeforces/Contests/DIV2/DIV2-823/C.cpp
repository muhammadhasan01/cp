#include <bits/stdc++.h>

using namespace std;

const int K = 10;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> pos(K);
    for (int i = 0; i < n; i++) {
        int num = s[i] - '0';
        pos[num].emplace_back(i);
    }
    vector<bool> done(n);
    string res = "";
    vector<int> cnt(K);
    for (int x = 0; x < K; x++) {
        for (int i : pos[x]) {
            for (int j = i; j >= 0; j--) {
                if (done[j]) {
                    break;
                }
                done[j] = true;
                if (i == j) {
                    res += s[j];
                } else {
                    int num = s[j] - '0';
                    cnt[min(num + 1, 9)]++;
                }
            }
        }
        while (cnt[x] > 0) {
            res += char(int('0') + x);
            cnt[x]--;
        }
    }
    cout << res << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}