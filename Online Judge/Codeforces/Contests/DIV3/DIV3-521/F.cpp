#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct DequeMax {
    deque<T> dq;

    bool isEmpty() {
        return dq.empty();
    }

    void add(T x) {
        while (!dq.empty() && dq.back() < x) {
            dq.pop_back();
        }
        dq.emplace_back(x);
    }

    void remove(T x) {
        if (dq.empty() || dq.front() != x) {
            return;
        }
        dq.pop_front();
    }

    T getMax() {
        return dq.front();
    }
};

const long long INF = 1e16;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k, x;
    cin >> n >> k >> x;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<long long> dp(n + 1, -INF);
    dp[0] = 0;
    for (int p = 1; p <= x; p++) {
        vector<long long> ndp(n + 1, -INF);
        DequeMax<long long> dq;
        dq.add(dp[p - 1]);
        int len = k + 1;
        for (int i = p; i <= n; i++) {
            int j = i - len;
            if (j >= p - 1) {
                dq.remove(dp[j]);
            }
            ndp[i] = a[i] + dq.getMax();
            dq.add(dp[i]);
        }
        dp.swap(ndp);
    }
    long long ans = -1;
    for (int i = n - k + 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
    
    return 0;
}