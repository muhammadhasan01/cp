#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

int cnt[N];
long long pre[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string useless;
    cin >> useless;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pre[x] += x;
        cnt[x]++;
    }
    for (int i = 1; i < N; i++) {
        pre[i] += pre[i - 1];
        cnt[i] += cnt[i - 1];
    }
    long long ans = LLONG_MAX;
    for (int x = 1; x < N; x += 2) {
        long long res = 0;
        for (int l = -1, r = x; r < N; r *= 2) {
            int num = cnt[r] - (l == -1 ? 0 : cnt[l]);
            long long sum = pre[r] - (l == -1 ? 0 : pre[l]);
            long long cur = 1LL * num * r - sum;
            res += cur;
            l = r;
        }
        ans = min(ans, res);
    }
    cout << ans << '\n';
    
    return 0;
}