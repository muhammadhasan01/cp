#include <bits/stdc++.h>

using namespace std;

void solve() {
    int div = 0;
    int rating;
    cin >> rating;
    if (1900 <= rating) {
        div = 1;
    } else if (1600 <= rating && rating < 1900) {
        div = 2;
    } else if (1400 <= rating && rating < 1600) {
        div = 3;
    } else {
        div = 4;
    }
    cout << "Division " << div << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}