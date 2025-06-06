#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e16;

long long n, ans;
string s;

long long F(int i, int j) {
    long long ret = 0;
    if (i != j && s[j] == '0') return INF;
    for (int it = j; it <= i; it++) {
        ret = 10 * ret + (s[it] - '0');
    }
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    long long cur = 1;
    int i = s.length() - 1;
    while (i >= 0) {
        int pos = i;
        for (int j = i; j >= max(0, i - 10); j--) {
            if (F(i, j) < n) {
                pos = j;
            }
        }
        ans += cur * F(i, pos);
        cur *= n;
        i = pos - 1;
    }
    cout << ans << '\n';

    return 0;
}