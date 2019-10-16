#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    s += s;
    int dp = 0, ans = 1;
    char last = '#';
    for (auto e : s) {
        if (e == last) {
            dp = 1;
        } else {
            ++dp;
            ans = max(ans, dp);
            last = e;
        }
    }
    cout << min(ans, (int)s.size() / 2) << '\n';

    return 0;
}
