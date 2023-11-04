#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    int maksimal = INT_MIN;
    int minimal = INT_MAX;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        maksimal = max(maksimal, x);
        minimal = min(minimal, x);
    }
    cout << maksimal << ' ' << minimal << '\n';
    
    return 0;
}