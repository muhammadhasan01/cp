#include <bits/stdc++.h>
using namespace std;

long long x;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x;
    for (int i = 0; i <= 32; i++) {
        long long k = (1LL << i);
        if (k > x) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}
