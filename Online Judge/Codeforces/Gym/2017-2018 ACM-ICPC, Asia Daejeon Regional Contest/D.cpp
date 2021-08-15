#include <bits/stdc++.h>

using namespace std;

const string TERM = "1";

void solve() {
    map<string, bool> mp;
    string str;
    cin >> str;
    auto get_val = [&](string& s) -> string {
        long long res = 0;
        for (char cc : s) {
            int num = cc - '0';
            res += 1LL * num * num;
        }
        return to_string(res);
    };
    while (true) {
        if (str == TERM) {
            cout << "HAPPY" << '\n';
            return;
        }
        if (mp.count(str)) {
            cout << "UNHAPPY" << '\n';
            return;
        }
        mp[str] = true;
        str = get_val(str);
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}