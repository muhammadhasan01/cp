#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            continue;
        } else {
            if (i + 1 < n && v[i + 1] > 0) {
                v[i + 1] -= 1;
                continue;
            }
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
    
    return 0;
}