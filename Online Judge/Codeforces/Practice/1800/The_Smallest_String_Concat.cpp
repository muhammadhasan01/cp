#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;
int n;
string s[N];

bool cmpr(string a, string b) {
    return a + b < b + a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    sort(s + 1, s + 1 + n, cmpr);
    for (int i = 1; i <= n; i++) {
        cout << s[i];
    }
    cout << '\n';

    return 0;
}
