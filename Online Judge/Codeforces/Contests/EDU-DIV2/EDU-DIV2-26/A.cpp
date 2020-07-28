#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin.ignore();
    getline(cin, s);
    int ans = 0, res = 0;
    for (auto& e : s) {
        if (e == ' ') {
            ans = max(ans, res);
            res = 0;
        } else if ('A' <= e && e <= 'Z') { 
            ++res;
        }
    }
    ans = max(ans, res);
    cout << ans << '\n';

    return 0;
}