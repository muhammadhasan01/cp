#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    string s(n, '#');
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    s[k - 1] = tolower(s[k - 1]);
    cout << s << '\n';

    return 0;
}