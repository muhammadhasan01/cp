#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    set<string> C = {"ABC", "ARC", "AGC", "AHC"};
    set<string> S;
    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        S.emplace(s);
    }
    for (string c : C) {
        if (S.count(c)) {
            continue;
        }
        cout << c << '\n';
        return 0;
    }
    assert(false);

    return 0;
}