#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    cout << (n > 0 ? "positif" : (n == 0 ? "nol" : "negatif")) << '\n';

    return 0;
}