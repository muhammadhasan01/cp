#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int x;
    cin >> x;
    cout << (__builtin_popcount(x) == 1 ? "ya" : "bukan") << '\n';
    
    return 0;
}