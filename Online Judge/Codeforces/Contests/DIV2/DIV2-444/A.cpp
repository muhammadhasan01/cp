#include <bits/stdc++.h>

using namespace std;

string s;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int n = s.length();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            for (int j = i + 1; j < n; j++) {
                if (s[j] == '0') ++cnt;
            }
            break;
        }
    }
    cout << (cnt >= 6 ? "yes" : "no") << "\n";

    return 0;
}