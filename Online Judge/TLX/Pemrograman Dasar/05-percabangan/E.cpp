#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    if (n <= 9) {
        cout << "satuan" << '\n';
    } else if (n <= 99) {
        cout << "puluhan" << '\n';
    } else if (n <= 999) {
        cout << "ratusan" << '\n';
    } else if (n <= 9999) {
        cout << "ribuan" << '\n';
    } else {
        cout << "puluhribuan" << '\n';
    }
    
    return 0;
}