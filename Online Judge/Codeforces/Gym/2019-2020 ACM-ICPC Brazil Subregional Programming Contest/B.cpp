#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int n;
int a[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    bool flag = true;
    for (int i = 2; i <= n; i++) {
        if (a[1] < a[i]) {
            flag = false;
            break;
        }
    }
    cout << (flag ? 'S' : 'N') << '\n';

    return 0;
}