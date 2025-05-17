#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long l, a;
    cin >> l >> a;
    vector<long long> h(l + 1);
    for (int i = 0; i <= l; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < l; i++) {
        long long climb = h[i+1] - h[i];
        if (climb > a) {
            cout << "BUG REPORT\n";
            return 0;
        }
    }
    cout << "POSSIBLE\n";
    
    return 0;
}