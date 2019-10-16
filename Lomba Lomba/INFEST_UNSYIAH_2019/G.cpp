#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int cnt = 1;
    for (int i = 0; i < (int) s.size(); i++) {
        if ('A' <= s[i] && s[i] <= 'Z') cnt++;
    }
    cout << cnt << '\n';

    return 0;
}
