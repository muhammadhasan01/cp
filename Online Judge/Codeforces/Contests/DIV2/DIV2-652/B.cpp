#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int tc;
int n;
char s[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    int pos = n + 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            pos = i;
            break;
        }
    }
    if (pos == n + 1) {
        for (int i = 1; i <= n; i++) {
            cout << s[i];
        }
        cout << '\n';
        return;
    }
    int furth = -1;
    for (int i = n; i > pos; i--) {
        if (s[i] == '0') {
            furth = i;
            break;
        }
    }
    if (furth == -1) {
        for (int i = 1; i <= n; i++) {
            cout << s[i];
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i < pos; i++) cout << s[i];
    for (int i = furth; i <= n; i++) cout << s[i];
    cout << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}