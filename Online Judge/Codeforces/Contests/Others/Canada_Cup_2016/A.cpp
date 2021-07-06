#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
char s[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '>') {
            break;
        }
        ans++;
    }
    for (int i = n; i >= 1; i--) {
        if (s[i] == '<') {
            break;
        }
        ans++;
    }
    cout << ans << '\n';

    return 0;
}