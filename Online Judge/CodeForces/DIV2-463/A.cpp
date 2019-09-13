#include <bits/stdc++.h>
using namespace std;

string a;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a;
    int n = a.size();
    if (2 * n <= 10000) {
        cout << a;
        reverse(a.begin(),a.end());
        cout << a;
        cout << '\n';
    }

    return 0;
}
