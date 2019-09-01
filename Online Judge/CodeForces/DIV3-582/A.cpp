#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<int> v(2);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        v[x & 1]++;
    }
    cout << min(v[0], v[1]) << '\n';

    return 0;
}
