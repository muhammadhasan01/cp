#include <bits/stdc++.h>
using namespace std;

string s;
int n;

bool check(string a) {
    int k = a.size();
    for (int i = 0; i < k; i++) {
        if (a[i] != a[k - i - 1]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.length();
    s = '#' + s;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        string temp = "";
        for (int j = i; j <= n; j++) {
            temp += s[j];
            if (!check(temp)) ans = max(ans, j - i + 1);
        }
    }
    cout << ans << '\n';

    return 0;
}
