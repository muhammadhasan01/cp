#include <bits/stdc++.h>

using namespace std;

string s;

string change(int x) {
    string ret = to_string(x);
    if ((int) ret.size() == 1) ret = "0" + ret;
    return ret;
}

bool check(int x, int y) {
    string ss = change(x) + change(y);
    string gg = ss;
    reverse(gg.begin(), gg.end());
    return (ss == gg);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int hh = stoi(s.substr(0, 2));
    int mm = stoi(s.substr(3, 2));
    int ans = 0;
    while (true) {
        if (check(hh, mm)) break;
        ++ans;
        int now = (hh * 60 + mm + 1) % 1440;
        hh = now / 60;
        mm = now % 60;
    }
    cout << ans << '\n';

    return 0;
}