#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
const int N = 2e5 + 5;
const int K = 5;

int n, k, b, c;
long long t[N];
long long sum[K];
priority_queue<long long> pq[K];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> b >> c;
    b = min(b, 5 * c);
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    sort(t + 1, t + 1 + n);
    auto get_rem = [&](int x) -> int {
        return (x % K + K) % K;
    };
    auto get_div = [&](int x) -> int {
        return (x - get_rem(x)) / K;
    };
    long long ans = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < K; j++) {
            int cur = get_rem(t[i] + j);
            int now = get_div(t[i] + j);
            long long cst = 1LL * j * c - 1LL * now * b;
            pq[cur].emplace(cst);
            sum[cur] += cst;
        }
        for (int j = 0; j < K; j++) {
            while ((int) pq[j].size() > k) {
                long long cst = pq[j].top();
                pq[j].pop();
                sum[j] -= cst;
            }
        }
        for (int j = 0; j < K; j++) {
            int cur = get_rem(t[i] + j);
            if ((int) pq[cur].size() != k) {
                continue;
            }
            int now = get_div(t[i] + j);
            long long cst = 1LL * now * b * k;
            cst += sum[cur];
            ans = min(ans, cst);
        }
    }
    cout << ans << '\n';

    return 0;
}