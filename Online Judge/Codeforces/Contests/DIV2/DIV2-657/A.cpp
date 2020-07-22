#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const string str = "abacaba";

int tc;
int n, len;
char a[N], b[N];

bool BF(int x) {
    for (int i = x, j = 0; j < len; i++, j++) {
        if (a[i] == '?') {
            a[i] = str[j];
            continue;
        }
        if (a[i] != str[j]) return false;
    }
    for (int i = 1; i < x; i++) {
        bool flag = true;
        for (int j = i, k = 0; k < len; j++, k++) {
            if (a[j] == str[k]) continue;
            flag = false;
            break;
        }
        if (flag) return false;
    }
    for (int i = x + 1; i <= n - len + 1; i++) {
        bool flag = true;
        for (int j = i, k = 0; k < len; j++, k++) {
            if (a[j] == str[k]) continue;
            flag = false;
            break;
        }
        if (flag) return false;
    }
    return true;
}

void GET(int x) {
    for (int i = 1; i < x; i++) cout << (a[i] == '?' ? 'z' : a[i]);
    for (int i = x, j = 0; i <= x + len - 1; i++, j++) cout << str[j];
    for (int i = x + len; i <= n; i++) {
        if (a[i] == '?') a[i] = 'z';
        cout << a[i];
    }
    cout << '\n';
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    for (int i = 1; i <= n - len + 1; i++) {
        for (int j = 1; j <= n; j++) a[j] = b[j];
        if (BF(i)) {
            cout << "YES" << '\n';
            GET(i);
            return;
        }
    }
    cout << "NO" << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    len = str.size();
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}