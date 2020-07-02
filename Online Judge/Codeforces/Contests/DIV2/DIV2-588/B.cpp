#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') continue;
        if (k > 0) {
            if (i == 0) {
                if (n == 1) {
                    if (s[i] != '0') k--;
                    s[i] = '0';
                } else {
                    if (s[i] != '1') k--;
                    s[i] = '1';
                }
            } else {
                if (s[i] != '0')k--;
                s[i] = '0';
            }
        } else {
            break;
        }
    }
    cout << s << '\n';

    return 0;
}
