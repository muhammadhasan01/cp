#include <bits/stdc++.h>

using namespace std;

int tc;
int a, b;

int f(int x) {
    if (x == 0) return 0;
    else if (x <= 2) return 1;
    else return 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> a >> b;
        int dif = abs(a - b);
        cout << dif / 5 + f(dif % 5) << '\n';
    }

    return 0;
}
