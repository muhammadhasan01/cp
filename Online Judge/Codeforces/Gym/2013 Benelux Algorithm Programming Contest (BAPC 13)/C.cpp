#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    auto is_valid = [&](string& e, string& d) -> bool {
        int x = e.size(), y = d.size();
        if (x != y) return false;
        vector<int> inp(26, -1), out(26, -1);
        for (int i = 0; i < x; i++) {
            int ce = e[i] - 'a';
            int cd = d[i] - 'a';
            if (inp[cd] == -1) {
                inp[cd] = ce;
            } else if (inp[cd] != ce) {
                return false;
            }
            if (out[ce] == -1) {
                out[ce] = cd;
            } else if (out[ce] != cd) {
                return false;
            }
        }
        return true;
    };

    string d, x;
    cin >> d >> x;
    bool ok = false;
    vector<set<int>> in(26), out(26);
    for (int i = 0; i < n; i++) {
        if (!is_valid(v[i], d)) continue;
        ok = true;
        for (int j = 0; j < (int) d.size(); j++) {
            int ce = v[i][j] - 'a';
            int cd = d[j] - 'a';
            in[ce].emplace(cd);
            out[cd].emplace(ce);
        }
    }
    if (!ok) {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    vector<char> ans(26);
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        int cur_in = i;
        if ((int) in[cur_in].size() == 1) {
            int cur_out = *in[cur_in].begin();
            if ((int) out[cur_out].size() == 1) {
                ans[i] = char(cur_out + int('a'));
                continue;
            }
        }
        ans[i] = '?';
        ++cnt;
    }
    if (cnt == 1) {
        int cur_out = -1;
        for (int i = 0; i < 26; i++) {
            if (out[i].empty()) {
                cur_out = i;
                break;
            }
        }
        assert(cur_out != -1);
        for (int i = 0; i < 26; i++) {
            if (ans[i] != '?') continue;
            ans[i] = char(cur_out + int('a'));
        }
    }
    for (char cc : x) {
        int num = cc - 'a';
        cout << ans[num];
    }
    cout << '\n';
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