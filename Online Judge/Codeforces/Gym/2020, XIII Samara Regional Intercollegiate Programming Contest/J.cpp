#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << 3 << '\n';
    for (int i = 0; i < 3; i++) {
        cout << 5 << (i == 2 ? '\n' : ' ');
    }
    cout << 10 << '\n';
    for (int i = 0; i < 7; i++) {
        cout << 1 << ' ';
    }
    for (int i = 7; i < 10; i++) {
        cout << 10 << (i == 9 ? '\n' : ' ');
    }

    return 0;
}