#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int l = 2, r = 5;
    for (int i = l; i <= r; i++) {
        for (int j = i; j <= r; j++) {
            for (int k = i; k <= j; k++) {
                a[k]++;
            }
        }
    }
    for (int i = 1; i <= 10; i++) {
        cout << a[i] << (i == 10 ? '\n' : ' ');
    }

    return 0;
}
