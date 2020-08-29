#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s; cin >> s;
    deque<char> str;
    str.assign(s.begin(), s.end());
    while (!str.empty() && str[0] == '0')
        str.pop_front();
    for (int i = 0; i < (int) str.size(); i++) {
        if (str[i] == '.') {    
            while (!str.empty() && str.back() == '0')
                str.pop_back();
            break;
        }
    }
    if (str.empty() || (str[0] == '.' && (int) str.size() == 1)) {
        cout << 0 << '\n';
        return 0;
    }
    if (str[0] == '.') {
        for (int i = 1; i < (int) str.size(); i++) {
            if (str[i] == '0') continue;
            for (int j = i; j < (int) str.size(); j++) {
                cout << str[j];
                if (j != (int) str.size() - 1 && j == i) cout << '.';
            }
            cout << "E-" << i << '\n';
            break;
        }
    } else {
        if ((int) str.size() == 1) {
            cout << str[0] << '\n';
            return 0;
        }
        if ((int) str.size() == 2 && str[1] == '.') {
            cout << str[0] << '\n';
            return 0;
        }
        int pos = (int) str.size() - 1;
        for (int i = 0; i < (int) str.size(); i++) {
            if (str[i] != '.') continue;
            pos = i - 1;
            break;
        }
        while (!str.empty() && (str.back() == '0' || str.back() == '.'))
            str.pop_back();
        cout << str[0];
        bool ok = true;
        for (int j = 1; j < (int) str.size(); j++) {
            if (str[j] == '.') continue;
            if (ok) {
                cout << '.';
                ok = false;
            }
            cout << str[j];
        }
        if (pos > 0) {
            cout << 'E' << pos << '\n';
        }
    }

    return 0;
}