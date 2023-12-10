#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    if (k < n / 2 || k == n) {
        cout << -1 << '\n';
        return 0;
    }
    string s = string(n / 2, '(') + string(n / 2, ')');
    int cur = n / 2;
    int parity = 1;
    string L = "", R = "";
    while (cur < k) {
        s.erase(s.begin());
        s.pop_back();
        if (parity) {
            L += "()";
        } else {
            R += "()";
        }
        cur++;
        parity ^= 1;
    }
    cout << L << s << R << '\n';
    
    return 0;
}