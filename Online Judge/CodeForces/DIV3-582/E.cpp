#include <bits/stdc++.h>
using namespace std;

int n;
string s, t;
string pat = "abc";

bool check(string a, string b, int i, int j) {
    return (a[i] == b[j] && a[i + 1] == b[j + 1]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s >> t;
    string tpat = pat;
    do {
        string k = tpat;
        if (n > 1) k += tpat;
        bool flag = true;
        for (int i = 0; i < 5; i++) {
            if (check(k, s, i, 0) || check(k, t, i, 0)) {
                flag = false;
                break;
            }
        }

        if (!flag) continue;

        cout << "YES" << '\n';
        for (int i = 1; i <= n; i++) {
            cout << tpat;
        }cout << '\n';
        return 0;
    } while (next_permutation(tpat.begin(), tpat.end()));

    tpat = pat;
    do {
        if (check(tpat, s, 0, 0) || check(tpat, t, 1, 0)) continue;
        if (check(tpat, s, 1, 0) || check(tpat, t, 0, 0)) continue;
        cout << "YES" << '\n';
        for (int j = 0; j < 3; j++) {
            for (int i = 1; i <= n; i++) {
                cout << tpat[j];
            }
        }
        cout << '\n';
        return 0;
    } while (next_permutation(tpat.begin(), tpat.end()));
    cout << "NO" << '\n';

    return 0;
}
