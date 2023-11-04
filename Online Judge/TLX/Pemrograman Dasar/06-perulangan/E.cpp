#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int x;
    cin >> x;
    bool isDuaPangkat = true;
    while (x > 1) {
        if (x % 2 == 1) {
            isDuaPangkat = false;
            break;
        }
        x /= 2;
    }
    cout << (isDuaPangkat ? "ya" : "bukan") << '\n';
    
    return 0;
}