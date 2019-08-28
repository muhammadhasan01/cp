#include <bits/stdc++.h>
using namespace std;

const int N = 1500 + 50;
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
    bool ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 1; j--) {
            if (a[i] < a[j]) ans ^= 1;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        len = len * (len - 1) / 2;
        if (len & 1) ans ^= 1;
        puts(ans ? "odd" : "even");
    }


    return 0;
}
