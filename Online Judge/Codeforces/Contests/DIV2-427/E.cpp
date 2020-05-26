#include <bits/stdc++.h>

using namespace std;

int n, x, y, xoy;

int ask(const vector<int>& a) {
    if (a.empty()) return -1;
    int len = a.size();
    cout << "? " << len << " ";
    for (int i = 0; i < len - 1; i++) cout << a[i] << " ";
    cout << a[len - 1] << endl;
    int ret;
    cin >> ret;
    return ret;
}

int solve(const vector<int>& a) {
    int l = 0, r = (int) a.size() - 1, pos = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        vector<int> b;
        for (int i = 0; i <= mid; i++) {
            b.push_back(a[i]);
        }
        int val = ask(b);
        if (val == y || val == xoy) {
            pos = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return a[pos];
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x >> y;
    xoy = (x ^ y);
    int bit_dif = -1;
    int dif = 0;
    for (int bit = 0; bit <= 9; bit++) {
        vector<int> a;
        for (int i = 1; i <= n; i++) {
            if (i & (1 << bit)) {
                a.push_back(i);
            }
        }
        int val = ask(a);
        if (val == y || val == xoy) {
            bit_dif = bit;
            dif |= (1 << bit);
        }
    }
    assert(bit_dif != -1 && dif > 0);
    vector<int> a, b;
    for (int i = 1; i <= n; i++) {
        if (i & (1 << bit_dif)) {
            a.push_back(i);
        } else {
            b.push_back(i);
        }
    }
    if ((int) a.size() > (int) b.size()) swap(a, b);
    int pos_1 = solve(a);
    int pos_2 = (pos_1 ^ dif);
    if (pos_1 > pos_2) swap(pos_1, pos_2);
    cout << "! " << pos_1 << " " << pos_2 << endl;

    return 0;
}