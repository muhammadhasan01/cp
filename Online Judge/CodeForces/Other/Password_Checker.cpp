#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int n = s.length();
    bool ok = true;
    ok &= (n >= 5);
    bool lc = false, cc = false, nc = false;
    for (auto e : s) {
        if ('a' <= e && e <= 'z') {
            lc = true;
        } else if ('A' <= e && e <= 'Z') {
            cc = true;
        } else if ('0' <= e && e <= '9') {
            nc = true;
        }
    }
    ok = (ok && lc && cc && nc);
    puts(ok ? "Correct" : "Too weak");


    return 0;
}
