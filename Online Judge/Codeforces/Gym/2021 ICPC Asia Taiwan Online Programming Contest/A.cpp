#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<tuple<int, int, int, int>> v(n);
    vector<string> name(n);
    for (int i = 0; i < n; i++) {
        int g, s, b;
        cin >> g >> s >> b;
        cin.ignore();
        string str;
        getline(cin, str);
        name[i] = str;
        v.emplace_back(g, s, b, i);
    }
    sort(v.begin(), v.end(), [&](auto& lhs, auto& rhs) {
        auto [gi, si, bi, x] = lhs;
        auto [gj, sj, bj, y] = rhs;
        if (gi == gj) {
            if (si == sj) {
                return bi > bj;
            }
            return si > sj;
        }
        return gi > gj;
    });
    cout << name[get<3>(v[0])] << '\n';
    
    return 0;
}