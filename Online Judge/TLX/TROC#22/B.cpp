#include <bits/stdc++.h>

using namespace std;

const int K = 3;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << char(int('a') + i % K);
    }
    cout << '\n';
    
    return 0;
}