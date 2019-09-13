#include <bits/stdc++.h>
using namespace std;

string s;
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.length();
    int cnt = 0;
    for (auto e : s) {
        if (e == 'a') cnt++;
    }
    while (n >= 2 * cnt) n--;
    cout << n << '\n';

    return 0;
}
