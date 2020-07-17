#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int tc;
int n;
int pre[N][30];
char a[N];

int getRes(int l, int r, int k) {
    int freq = pre[r][k] - pre[l - 1][k];
    return (r - l + 1) - freq;
}

int findAns(int l, int r, int k) {
    if (l == r) return getRes(l, r, k);
    int mid = (l + r) >> 1;
    int leftz = getRes(l, mid, k) + findAns(mid + 1, r, k + 1);
    int rightz = findAns(l, mid, k + 1) + getRes(mid + 1, r, k);
    return min(leftz, rightz);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            for (int it = 0; it < 26; it++) {
                pre[i][it] = pre[i - 1][it];
            }
            pre[i][(int) (a[i] - 'a')]++;
        }
        cout << findAns(1, n, 0) << '\n';
    }

    return 0;
}