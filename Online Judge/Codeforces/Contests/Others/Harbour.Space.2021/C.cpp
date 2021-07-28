#include <bits/stdc++.h>

using namespace std;

void solve() {
    string str;
    cin >> str;
    int n = str.length();
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (str[i] == '?') {
            pos.emplace_back(i);
        }
    }
    int len = pos.size();
    int ans = n;
    for (int mask = 0; mask < (1 << len); mask++) {
        string s = str;
        for (int i = 0; i < len; i++) {
            bool b = mask & (1 << i);
            if (b) {
                s[pos[i]] = '1';
            } else {
                s[pos[i]] = '0';
            }
        }
        vector<int> score(2, 0);
        vector<int> cnt(2, n / 2);
        int res = n;
        for (int i = 0; i < n; i++) {
            int turn = i % 2;
            int othr = 1 - turn;
            score[turn] += (s[i] == '1');
            cnt[turn]--;
            for (int it = 0; it < 2; it++) {
                if (score[othr] + cnt[othr] < score[turn]) {
                    res = i + 1;
                    break;
                }
                swap(turn, othr);
            }
            if (res == i + 1) {
                break;
            }
        }
        ans = min(ans, res);
    }
    cout << ans << '\n';
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