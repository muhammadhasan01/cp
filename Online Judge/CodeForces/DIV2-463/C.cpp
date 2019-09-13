#include <bits/stdc++.h>
using namespace std;

int n, a, b;

vector<int> perm(int x, int sz) {
    vector<int> ret(sz, 0);
    int i = 0, j = sz - 1, trn = 1;
    while (i < j) {
        if (trn) {
            ret[i] = x + j;
            i++;
        } else {
            ret[j] = x + i;
            j--;
        }
        trn ^= 1;
    }
    ret[i] = x;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b;
    int x = -1, y = -1;
    for (int i = 0; i <= n / a; i++) {
        int cur = n - i * a;
        if (cur % b == 0) {
            x = i;
            y = cur / b;
            break;
        }
    }
    if (x == -1 && y == -1) {
        cout << -1 << '\n';
        return 0;
    }
    vector<int> temp;
    int pos = 1;
    for (int i = 1; i <= x; i++) {
        temp = perm(pos, a);
        pos += a;
        for (auto e : temp) cout << e << " ";
    }
    for (int i = 1; i <= y; i++) {
        temp = perm(pos, b);
        pos += b;
        for (auto e : temp) cout << e << " ";
    }

    return 0;
}
