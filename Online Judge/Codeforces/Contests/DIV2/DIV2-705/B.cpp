#include <bits/stdc++.h>

using namespace std;

map<char, char> mp = {{'0', '0'}, {'1', '1'}, {'2', '5'}, {'5', '2'}, {'8', '8'}, {':', ':'}};

int h, m;
string s;

void solve() {
    cin >> h >> m;
    cin >> s;
    int hour = stoi(s.substr(0, 2));
    int minute = stoi(s.substr(3, 2));
    while (1) {
        string H = to_string(hour);
        string M = to_string(minute);
        if ((int) H.size() == 1) H = "0" + H;
        if ((int) M.size() == 1) M = "0" + M;
        string cur = H + ":" + M;
        reverse(cur.begin(), cur.end());
        bool ok = true;
        for (char& cc : cur) {
            if (mp.count(cc)) {
                cc = mp[cc];
            } else {
                ok = false;
            }
        }
        if (ok) {
            if (stoi(cur.substr(0, 2)) < h && stoi(cur.substr(3, 2)) < m) {
                cout << H + ":" + M << '\n';
                return;
            } 
        }
        minute++;
        if (minute == m) {
            minute = 0;
            hour++;
            if (hour == h) {
                hour = 0;
            }
        }
    }
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