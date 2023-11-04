#include <bits/stdc++.h>

using namespace std;

const int K = 3;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<vector<int>> a(K, vector<int>(K));
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) {
            cin >> a[i][j];
        }
    }

    int x = 0, y = 0;

    auto check = [&](vector<int>& v) {
        vector<int> ord(K);
        iota(ord.begin(), ord.end(), 0);
        do {
            if (v[ord[0]] == v[ord[1]] && v[ord[2]] != v[ord[1]]) {
                x++;
            }
            y++;
        } while (next_permutation(ord.begin(), ord.end()));
    };

    for (int i = 0; i < K; i++) {
        vector<int> v = {a[i][0], a[i][1], a[i][2]};
        vector<int> vvv  = {a[0][i], a[1][i], a[2][i]};
        check(v);
        check(vvv);
    }
    vector<int> d = {a[0][0], a[1][1], a[2][2]};
    vector<int> ddd = {a[2][0], a[1][1], a[0][2]};
    check(d);
    check(ddd);

    cout << fixed << setprecision(12) << ((double) x) / y << '\n';
    
    return 0;
}