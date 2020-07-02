#include<bits/stdc++.h>
using namespace std;

string a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    if (a.length() < b.length()) {
        sort(a.begin(), a.end(), greater<char>());
        cout << a << '\n';
        return 0;
    }
    multiset<char> ms;
    for (auto e : a) {
        ms.insert(e);
    }
    int pos = b.length() - 1;
    multiset<char> mst = ms;
    for (int i = 0; i < b.length(); i++) {
        auto it = ms.lower_bound(b[i]);
        if (i == b.length() - 1 && it == ms.begin() && *it == b[i]) pos = i;
        if (it != ms.begin()) pos = i;
        if (it == ms.end() || *it > b[i]) {
            break;
        } else if (*it == b[i]) {
            ms.erase(it);
        }
    }
    string ans = a;
    for (int i = 0; i < b.length(); i++) {
        if (i < pos) {
            auto it = mst.lower_bound(b[i]);
            ans[i] = *it;
            mst.erase(it);
        } else if (i == pos) {
            auto it = mst.lower_bound(b[i]);
            it--;
            ans[i] = *it;
            mst.erase(it);
        } else {
            auto it = mst.end();
            it--;
            ans[i] = *it;
            mst.erase(it);
        }
    }
    cout << ans << '\n';

    return 0;
}
