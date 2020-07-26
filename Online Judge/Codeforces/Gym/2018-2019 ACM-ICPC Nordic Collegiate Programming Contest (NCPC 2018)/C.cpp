#include <bits/stdc++.h>

using namespace std;

const int N = 400;

int n;
bool d[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        d[x] = 1;
    }
    int ans = 0;
    for (int i = 2; i < N; i++) {
        int res = 0;
        for (int j = i - 1; j >= 1; j--) {
            if (d[j]) {
                res += i - j;
            }
        }
        if (res >= 20) {
            ++ans;
            for (int j = i - 1; j >= 1; j--) {
                d[j] = false;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}