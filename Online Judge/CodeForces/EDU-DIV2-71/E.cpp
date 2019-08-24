#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cout << "? ";
    for (int i = 1; i <= 100; i++) cout << i << (i == 100 ? '\n' : ' ');
    cout << flush;
    cin >> a;
    cout << "? ";
    for (int i = 1; i <= 100; i++) cout << (i << 7) << (i == 100 ? '\n' : ' ');
    cout << flush;
    cin >> b;
    int res = 0, k = (1 << 7) - 1;
    res |= (a & (k << 7));
    res |= (b & k);
    cout << "! " << res << '\n';
    cout << flush;

    return 0;
}
