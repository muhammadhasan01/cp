#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    vector<int> pos(n + 1);
    auto update_pos = [&]() -> void {
        for (int i = 1; i <= n; i++) {
            pos[p[i]] = i;
        }    
    };
    update_pos();
    for (int i = 1; i <= n; i++) {
        int cur = abs(i - pos[i]);
        if (cur % 2 == 1) {
            cout << -1 << '\n';
            return;
        }
    }
    vector<int> ans;
    for (int it = n; it > 1; it -= 2) {
        int num = it;
        for (int rep = 0; rep < 10; rep++) {
            if (pos[num] == num && pos[num - 1] == num - 1) {
                break;
            }
            if (pos[num] == 1 && pos[num - 1] == 2) {
                ans.emplace_back(num);
                reverse(p.begin() + 1, p.begin() + num + 1);
            } else if (pos[num] - pos[num - 1] == 1) {
                ans.emplace_back(pos[num]);
                reverse(p.begin() + 1, p.begin() + pos[num] + 1);
            } else if (pos[num - 1] - pos[num] == 1) {
                ans.emplace_back(pos[num - 1] + 1);
                reverse(p.begin() + 1, p.begin() + pos[num - 1] + 2);
            } else if (pos[num] != 1) {
                ans.emplace_back(pos[num]);
                reverse(p.begin() + 1, p.begin() + pos[num] + 1);
            } else if (pos[num] == 1 && pos[num - 1] > 2) {
                ans.emplace_back(pos[num - 1] - 1);
                reverse(p.begin() + 1, p.begin() + pos[num - 1]);
            }
            update_pos();
        }
    }
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
    
    int tc = 1;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }
    
    return 0;
}