#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (s[0] == 'm') {
            continue;
        } else {
            int k = stoi(s);
            if (k != i) flag = false;
        }
    }
    cout << (flag ? "makes sense" : "something is fishy") << '\n';

    return 0;
}