#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> sprime(N);
    for (int i = 2; i < N; i++) {
        if (sprime[i] > 0) {
            continue;
        }
        for (int j = i; j < N; j += i) {
            sprime[j] = i;
        }
    }
    vector<vector<int>> divisors(N);
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            divisors[j].emplace_back(i);
        }
    }
    auto norm = [&](int x) -> int {
        int ret = 1;
        while (x > 1) {
            int p = sprime[x];
            ret = (ret * p);
            while (x % p == 0) {
                x /= p;
            }
        }
        return ret;
    };
    vector<int> dist(N, -1);
    vector<int> cnt(N);
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x = norm(x);
        if (dist[x] != -1) {
            continue;
        }
        dist[x] = 1;
        q.emplace(x);
        for (int d : divisors[x]) {
            cnt[d]++;
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int d = dist[u] + 1;
        vector<int> cur;
        {
            int x = u;
            while (x > 1) {
                int p = sprime[x];
                cur.emplace_back(p);
                x /= p;
            }
        }
        int len = cur.size();
        vector<int> val(1 << len);
        for (int i = 0; i < (1 << len); i++) {
            val[i] = u;
            for (int j = 0; j < len; j++) {
                if (i & (1 << j)) {
                    val[i] /= cur[j];
                }
            }
        }
        for (int i = 0; i < (1 << len); i++) {
            int sum = 0;
            for (int j = i; true; j = (j - 1) & i) {
                int c = __builtin_popcount(i ^ j);
                if (c % 2 == 0) {
                    sum += cnt[val[j]];
                } else {
                    sum -= cnt[val[j]];
                }
                if (j == 0) {
                    break;
                }
            }
            assert(sum >= 0);
            if (sum > 0 && dist[val[i]] == -1) {
                dist[val[i]] = d;
                q.emplace(val[i]);
            }
        }
    }
    cout << dist[1] << '\n';
    
    return 0;
}