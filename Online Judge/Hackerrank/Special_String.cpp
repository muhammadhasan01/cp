#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
int n;
char a[N];

long long f(long long x) {
    return x * (x + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    int i = 1, len;
    while (i <= n) {
        int j = 1;
        len = 0;
        char k = a[i + 1];
        while (i + j <= n && i - j >= 1 && a[i] != k && a[i + j] == a[i - j] && a[i + j] == k) {
            j++;
            len++;
        }
        if (len == 1) i = i + 1;
        else i += j;
        ans += (1LL) * len;
    }
    char x = a[1];
    len = 0;
    for (int i = 1; i <= n; i++) {
        if (x == a[i]) {
            len++;
        } else {
            ans += f(len);
            len = 1;
            x = a[i];
        }
    }
    ans += f(len);
    cout << ans << '\n';

    return 0;
}
