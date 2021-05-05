#include <bits/stdc++.h>

using namespace std;

int m, k;

void solve() {
    int res = (1 << m);
    if (k == 0) {
        for (int i = 0; i < res; i++) {
            cout << i << ' ' << i << " \n"[i == res - 1];
        }
        return;
    }
    int XOR = 0;
    for (int i = 0; i < res; i++) {
        XOR = (XOR ^ i);
    }
    if (XOR != 0 || k >= res) {
        cout << -1 << '\n';
        return;
    }
    vector<int> v(res);
    iota(v.begin(), v.end(), 0);
    swap(v[0], v[k]);
    for (int i = res - 1; i >= 0; i--) {
        cout << v[i] << ' ';
    }
    for (int i = 1; i < res; i++) {
        cout << v[i] << ' ';
    }
    cout << v[0] << '\n';
} 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> k;
    solve();

    return 0;
}