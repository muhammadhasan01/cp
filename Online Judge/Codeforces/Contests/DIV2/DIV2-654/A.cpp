#include <bits/stdc++.h>

using namespace std;

int tc;
long long n;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        cout << (n + 1) / 2 << '\n';
    }

    return 0;
}