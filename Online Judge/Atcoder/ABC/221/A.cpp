#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int a, b;
    cin >> a >> b;
    int dif = a - b;
    long long res = 1;
    for (int i = 0; i < dif; i++) {
        res = (res * 32);
    }
    cout << res << '\n';
    
    return 0;
}