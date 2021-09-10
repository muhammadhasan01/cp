#include <bits/stdc++.h>

using namespace std;

const vector<string> EEVEES = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    string str;
    cin >> str;
    for (string eeves : EEVEES) {
        int len = eeves.size();
        if (len != n) {
            continue;
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (str[i] == '.') {
                continue;
            }
            if (str[i] != eeves[i]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            continue;
        }
        cout << eeves << '\n';
        return 0;
    }
    
    return 0;
}