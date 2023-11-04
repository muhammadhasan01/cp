#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> a(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[0] == 5 && a[1] == 5 && a[2] == 7) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
    
    return 0;
}