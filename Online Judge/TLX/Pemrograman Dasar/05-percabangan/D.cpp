#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    if (n > 0) {
        cout << "positif" << '\n';
    } else if (n == 0) {
        cout << "nol" << '\n';
    } else {
        cout << "negatif" << '\n';
    }
    
    return 0;
}