#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    int cnt = 0;
    for (auto e : s) {
        if (e == '8') {
            cnt++;
        }
    }
    cout << min(n/11, cnt) << '\n';

    return 0;
}
