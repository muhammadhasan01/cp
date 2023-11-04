#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    map<pair<string, string>, int> cnt;
    bool yes = false;
    for (int i = 0; i < n; i++) {
        string x, y;
        cin >> x >> y;
        if (++cnt[{x, y}] > 1) {
            yes = true;
        }
    }
    cout << (yes ? "Yes" : "No") << '\n';
    
    return 0;
}