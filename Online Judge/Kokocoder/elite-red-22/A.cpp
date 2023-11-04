#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
int a[N];
long long pos[N], neg[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] > 0) a[i] = 1;
        else if (a[i] < 0) a[i] = 0;
    }
    long long a1 = 0, a2 = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            if (a[i]) pos[i] = 1;
            else neg[i] = 1;
        } else {
            if (a[i]) {
                pos[i] = 1 + pos[i - 1];
                neg[i] = neg[i - 1];
            } else {
                neg[i] = 1 + pos[i - 1];
                pos[i] = neg[i - 1];
            }
        }
        a1 += pos[i];
        a2 += neg[i];
    }

    cout << a2 << " " << a1 << '\n';

    return 0;
}