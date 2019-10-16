#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    s = "#" + s;
    int cur1 = 0, c1 = 0, cur2 = 0, c2 = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (s[i] == '?') {
            c1++;
        } else {
            cur1 += (s[i] - '0');
        }
    }
    for (int i = n / 2 + 1; i <= n; i++) {
        if (s[i] == '?') {
            c2++;
        } else {
            cur2 += (s[i] - '0');
        }
    }

    int lef = 2 * cur1 + 9 * c1;
    int rig = 2 * cur2 + 9 * c2;
    puts(lef == rig ? "Bicarp" : "Monocarp");

    return 0;
}
