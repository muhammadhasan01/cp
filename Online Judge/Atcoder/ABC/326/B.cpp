#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    auto check = [&](int x) -> bool {
        string s = to_string(x);
        int a = s[0] - '0';
        int b = s[1] - '0';
        int c = s[2] - '0';
        return a * b == c;
    };

    while (!check(n)) {
        n++;
    }
    cout << n << '\n';
    
    return 0;
}