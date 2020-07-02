#include <bits/stdc++.h>

using namespace std;

const int N = 30;
long long n;
int k;
string s;
long long ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    cin >> s;
    s = '#' + s;
    map<char, int> m;
    for (int i = 1; i <= k; i++) {
        char x;
        cin >> x;
        m[x]++;
    }
    long long l = 0;
    for (int i = 1; i <= n; i++) {
        if (m[s[i]]) {
            l++;
        } else {
            ans += l * (l + 1) / 2;
            l = 0;
        }
    }
    ans += l * (l + 1) / 2;
    cout << ans << '\n';

    return 0;
}
