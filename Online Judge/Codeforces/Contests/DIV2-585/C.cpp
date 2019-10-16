#include <bits/stdc++.h>
using namespace std;

int n;
string s, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s >> t;

    vector<int> c1, c2;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a' && t[i] == 'b') {
            c1.push_back(i);
        } else if (s[i] == 'b' && t[i] == 'a') {
            c2.push_back(i);
        }
    }

    vector<pair<int,int>> ans;
    int l1 = c1.size(), l2 = c2.size();

    if (abs(l1 - l2) & 1) {
        puts("-1");
        return 0;
    }

    for (int i = 0; i < l1 - 1; i += 2) {
        ans.push_back({c1[i], c1[i + 1]});
    }
    for (int j = 0; j < l2 - 1; j += 2) {
        ans.push_back({c2[j], c2[j + 1]});
    }

    if ((l1 & 1) && (l2 & 1)) {
        ans.push_back({c2.back(), c2.back()});
        ans.push_back({c2.back(), c1.back()});
    }

    cout << ans.size() << '\n';
    for (auto e : ans) {
        cout << e.first + 1 << " " << e.second + 1 << '\n';
    }


    return 0;
}
