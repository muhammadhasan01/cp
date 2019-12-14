#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
string a, b, c;
int va[30], vb[30], vc[30];
int ans, x, y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c;
    for (auto e : a) {
        va[e - 'a']++;
    }
    for (auto e : b) {
        vb[e - 'a']++;
    }
    for (auto e : c) {
        vc[e - 'a']++;
    }
    int mins = inf;
    for (int i = 0; i < 26; i++) {
        if (vb[i] == 0) continue;
        mins = min(mins, va[i] / vb[i]);
    }
    if (mins == inf) mins = 0;
    for (int i = 0; i <= mins; i++) {
        int cmins = inf;
        for (int j = 0; j < 26; j++) {
            if (i > 0) va[j] -= vb[j];
            if (vc[j] == 0) continue;
            cmins = min(cmins, va[j] / vc[j]);
        }
        if (cmins == inf) cmins = 0;
        int cur = i + cmins;
        if (cur > ans) {
            ans = cur;
            x = i, y = cmins;
        }
    }
    for (int i = 1; i <= x; i++) cout << b;
    for (int i = 1; i <= y; i++) cout << c;
    vector<int> v(30);
    for (auto e : a) {
        v[e - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        v[i] -= (vb[i] * x + vc[i] * y);
        for (int j = 1; j <= v[i]; j++) {
            cout << char(i + int('a'));
        }
    }
    cout << '\n';

    return 0;
}
