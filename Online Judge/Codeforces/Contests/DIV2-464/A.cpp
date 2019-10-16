#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;
int n;
int a[N];
bool vis[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int j = 1; j <= n; j++) {
        int cur = j;
        int c;
        for (c = 1; c <= 3; c++) {
            cur = a[cur];
            if (cur == j) break;
        }
        if (cur == j && c == 3) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");

    return 0;
}
