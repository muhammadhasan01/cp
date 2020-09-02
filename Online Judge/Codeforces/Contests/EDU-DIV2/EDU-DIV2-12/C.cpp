#include <bits/stdc++.h>

using namespace std;

const char C[] = {'a', 'b', 'c'};

string a;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a;
    int n = a.size();
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) continue;
        for (int it = 0; it < 3; it++) {
            if (C[it] == a[i - 1]) continue;
            if (i + 1 < n && C[it] == a[i + 1]) continue;
            a[i] = C[it];
        }
    }
    cout << a << '\n';

    return 0;
}