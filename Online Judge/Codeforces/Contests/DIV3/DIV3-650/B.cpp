#include <bits/stdc++.h>

using namespace std;

const int N = 45;

int tc;
int n;
int a[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        int odd = 0, even = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x % 2 != i % 2) {
                if (i % 2 == 0) even++;
                else odd++;
            }
        }
        if (even == odd) {
            cout << odd << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    
    return 0;
}