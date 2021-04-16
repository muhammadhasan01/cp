#include<bits/stdc++.h>

using namespace std;

string add(string s) {
    int i = (int)s.size() - 1;
    while (s[i] == '1') {
        s[i] = '0';
        i--;
    }
    s[i] = '1';
    return s;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string l, r;
    cin >> l >> r;
    if (l == r) {
        cout << r << '\n';
        return 0;
    }
    if (l[0] != r[0]) {
        for (int i = 1; i <= n; ++i) cout << "1";
        return 0;
    }
    if (add(l) == r || r.back() == '1') {
        cout << r << '\n';
        return 0;
    }
    cout << add(r) << '\n';
    
    return 0;
}