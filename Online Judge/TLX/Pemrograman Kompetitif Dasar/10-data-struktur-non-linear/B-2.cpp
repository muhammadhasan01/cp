#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    multiset<int, greater<int>> ms;
    for (int i = 0; i < n; i++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x;
            cin >> x;
            ms.emplace(x);
        } else if (tp == 2) {
            cout << *ms.begin() << '\n';
        } else if (tp == 3) {
            ms.erase(ms.begin());
        }
    }
    
    return 0;
}