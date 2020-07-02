#include <bits/stdc++.h>

using namespace std;

const int N = 6e2 + 5;
int n;
string s;
char x[2] = {'B', 'W'};
int ans[N], len;

char cv(char x) {
    return (x == 'B' ? 'W' : 'B');
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    s = '#' + s + '#';
    int c1 = 0, c2 = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'B') {
            c1++;
        } else {
            c2++;
        }
    }
    if (n % 2 == 0 && c1 & 1 && c2 & 1) {
        cout << -1 << '\n';
        return 0;
    }
    char x[2] = {'B', 'W'};
    int idx = (c1 & 1 ? 1 : 0);
    for (int i = 1; i <= n - 1; i++) {
        if (s[i] == x[idx]) {
            ans[++len] = i;
            s[i] = cv(s[i]);
            s[i + 1] = cv(s[i + 1]);
        }
    }
    cout << len << '\n';
    for (int i = 1; i <= len; i++) {
        cout << ans[i] << (i == len ? '\n' : ' ');
    }

    return 0;
}
