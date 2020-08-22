#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long M = 1e9 + 7;

int n;
int a[N];
int cnt[N], pre[N];
vector<int> primes[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pre[0] = 1; pre[1] = 2;
    for (int i = 2; i < N; i++) {
        pre[i] = (pre[i - 1] + pre[i - 1]) % M;
        if (!primes[i].empty()) continue;
        for (int j = i; j < N; j += i)
            primes[j].emplace_back(i);
    }
    cin >> n;
    int ans = pre[n] - 1;
    ans = (ans % M + M) % M;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x == 1) continue;
        int len = primes[x].size();
        int res = 0;
        for (int mask = 1; mask < (1 << len); mask++) {
            int val = 1, bit = 0;
            for (int j = 0; j < len; j++) {
                bool b = (mask & (1 << j));
                if (!b) continue;
                val *= primes[x][j], ++bit;
            }
            int cur_cnt = pre[cnt[val]++];
            if (bit % 2 == 0) cur_cnt = -cur_cnt;
            res = (res + cur_cnt);
            res = (res % M + M) % M;
        }
        ans = (ans - res);
        ans = (ans % M + M) % M;
    }
    cout << (ans % M + M) % M << '\n';

    return 0;
}