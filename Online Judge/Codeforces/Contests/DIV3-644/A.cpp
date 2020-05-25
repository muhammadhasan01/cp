#include <bits/stdc++.h>

using namespace std;

int tc;
int a, b;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> a >> b;
        int mini = 2e9;
        if (a > b) swap(a, b);
        if (a + a >= b) mini = min(mini, 4 * a * a);
        if (b >= 2 * a) mini = min(mini, b * b);
        cout << mini << '\n';
    }
    
    return 0;
}