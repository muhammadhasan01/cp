#include <bits/stdc++.h>

using namespace std;
using ld = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<string> names(n);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        string s;
        int n, r;
        cin >> s >> n >> r;
        names[i] = s;
        a[i] = make_pair(n, r);
    }
    auto get_value = [&](ld n, ld r) -> ld {
        return r * r * 2;
    };
    ld maksi = 0;
    int pos = -1;
    for (int i = 0; i < n; i++) {
        int n, r;
        tie(n, r) = a[i];
        auto cur = get_value(n, r);
        if (cur > maksi) {
            maksi = cur;
            pos = i;
        }
    }
    for (int i = 0; i < n; i++) {
        if (pos == i) {
            continue;
        }
        int n, r;
        tie(n, r) = a[i];
        auto cur = get_value(n, r);
        if (cur == maksi) {
            cout << "SERI" << '\n';
            return 0;
        }
    }
    cout << names[pos] << '\n';
    
    return 0;
}