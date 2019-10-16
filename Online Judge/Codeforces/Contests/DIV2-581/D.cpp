#include<bits/stdc++.h>
using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    reverse(s.begin(), s.end());
    string ns = s;
    int last = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            last++;
        } else {
            if (last > 0) {
                last--;
            } else {
                ns[i] = '0';
            }
        }
    }
    reverse(ns.begin(), ns.end());
    cout << ns << '\n';

    return 0;
}
