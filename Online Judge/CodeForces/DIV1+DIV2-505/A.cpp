#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    sort(s.begin(), s.end());
    if (n == 1) {
        puts("Yes");
        return 0;
    }
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");

    return 0;
}
