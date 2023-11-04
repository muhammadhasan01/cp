#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    cout << "masing-masing " << n / m << '\n';
    cout << "bersisa " << n % m << '\n'; 
    
    return 0;
}