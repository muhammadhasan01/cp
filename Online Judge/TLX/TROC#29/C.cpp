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
    vector<int> b(3);
    for (int i = 0; i < 3; i++) {
        cin >> b[i];
    }
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        int dif = abs(a[i] - b[i]);
        cnt += dif & 1;
    }
    if (cnt == 0 || cnt == 3) {
        cout << 0 << '\n';
    } else {
        cout << 1 << '\n';
    }
    
    return 0;
}