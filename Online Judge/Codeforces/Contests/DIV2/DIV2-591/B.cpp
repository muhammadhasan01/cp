#include <bits/stdc++.h>
using namespace std;

int q;
string s, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> s >> t;
        vector<bool> v1(30), v2(30);
        for (auto e : s) v1[e - 'a'] = 1;
        for (auto e : t) v2[e - 'a'] = 1;
        bool ok = false;
        for (int i = 0; i < 26; i++) {
            if (v1[i] == 1 && v2[i] == 1) {
                ok = true;
                break;
            }
        }
        puts(ok ? "YES" : "NO");
    }

    return 0;
}
