#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    map<string, bool> mp;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        cout << (mp.count(str) > 0 ? "YES" : "NO") << '\n';
        mp[str] = true;
    }

    return 0;
}