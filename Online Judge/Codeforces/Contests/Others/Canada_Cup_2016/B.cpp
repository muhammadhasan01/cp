#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    int len = str.size();
    long long val = 0;
    for (int i = 0; i < len - 1; i++) {
        int num = str[i] - '0';
        val = (val * 10) + num;
    }
    long long cc = 6 - (str[len - 1] - 'a');
    if (cc >= 4) {
        cc = 10 - cc;
    }
    long long row = (val + 3) / 4;
    long long ans = (row - 1) * 12 + cc;
    if (val % 4 == 1 || val % 4 == 2) {
        ans += val - 1;
    } else {
        ans += val - 3;
    }
    if (val % 2 == 0) {
        ans += 6;
    }
    cout << ans << '\n';

    return 0;
}