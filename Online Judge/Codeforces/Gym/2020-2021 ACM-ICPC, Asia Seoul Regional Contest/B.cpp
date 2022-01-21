#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> a(6), b(6);
    for (int i = 0; i < 6; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 6; i++) {
        cin >> b[i];
    }
    int x = 0, y = 36;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (a[i] > b[j]) {
                x++;
            }
        }
    }
    int g = __gcd(x, y);
    cout << x / g << '/' << y / g << '\n';
    
    return 0;
}