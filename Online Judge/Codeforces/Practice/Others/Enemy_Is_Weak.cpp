#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n;
int a[N];
long long ans;
vector<int> bit[N];

void add(int x, int val) {
    for ( ; x <= n; x += x & -x) {
        bit[x].push_back(val);
    }
}

int q1(int x, int val) {
    int ret = 0;
    for ( ; x > 0; x -= x & -x) {
        ret += bit[x].end() - upper_bound(bit[x].begin(), bit[x].end(), val);
    }
    return ret;
}

int q2(int x, int val) {
    int ret = 0;
    for ( ; x > 0; x -= x & -x) {
        ret += lower_bound(bit[x].begin(), bit[x].end(), val) - bit[x].begin();
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        add(i, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        sort(bit[i].begin(), bit[i].end());
    }
    for (int i = 2; i <= n - 1; i++) {
        long long le = q1(i - 1, a[i]);
        long long re = q2(n, a[i]) - q2(i, a[i]);
        ans += le * re;
    }
    cout << ans << '\n';

    return 0;
}
