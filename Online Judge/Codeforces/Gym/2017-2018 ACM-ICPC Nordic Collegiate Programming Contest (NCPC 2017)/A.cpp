#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5e5 + 5;

int n;
ll L, A, B, T, R;
ll pos[N];
ll dp[N];
int opt[N], go[N];

struct SegtreeLazy {
    vector<pair<ll, int>> t;
    vector<ll> lazy;
    SegtreeLazy() {
        t.resize(4 * N);
        lazy.assign(4 * N, 0);
    }

    pair<ll, int> combine(pair<ll, int> x, pair<ll, int> y) {
        return (x.first > y.first ? x : y);
    }

    void buill(int v, int s, int e) {
        if (s == e) {
            t[v] = make_pair(0, s);
            return;
        }
        int mid = (s + e) >> 1;
        buill(v << 1, s, mid);
        buill(v << 1 | 1, mid + 1, e);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    void push(int v, int s, int e) {
        if (lazy[v] == 0 || s == e) return;
        t[v << 1].first += lazy[v];
        t[v << 1 | 1].first += lazy[v];
        lazy[v << 1] += lazy[v];
        lazy[v << 1 | 1] += lazy[v];
        lazy[v] = 0;
    }

    void update(int v, int s, int e, int l, int r, ll val) {
        if (l > r) return;
        if (l == s && e == r) {
            t[v].first += val;
            lazy[v] += val;
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        update(v << 1, s, mid, l, min(r, mid), val);
        update(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    pair<ll, int> get(int v, int s, int e, int l, int r) {
        if (l > r)
            return {0, 0};
        if (l <= s && e <= r)
            return t[v];
        push(v, s, e);
        int mid = (s + e) >> 1;
        return combine(get(v << 1, s, mid, l, min(r, mid)), 
                get(v << 1 | 1, mid + 1, e, max(l, mid + 1), r));
    }
} sgt;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> L >> A >> B >> T >> R;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> pos[i];
    }
    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }
    sgt.buill(1, 1, n + 1);
    pos[n + 1] = L; opt[n + 1] = n + 1;
    for (int i = n; i >= 1; i--) {
        opt[i] = i;
        ll add = (pos[i + 1] - pos[i]);
        sgt.update(1, 1, n + 1, i + 1, n + 1, add);
        // Find when start drinking coffee
        ll start_pos = pos[i] + T * A;
        int l = i + 1, r = n + 1;
        int at_start = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (pos[mid] > start_pos) {
                r = mid - 1;
                at_start = mid;
            } else {
                l = mid + 1;
            }
        }
        if (at_start == -1) continue;
        // Find when stop drinking coffee
        ll stop_pos = start_pos + R * B;
        l = i + 1, r = n + 1;
        int at_stop = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (pos[mid] <= stop_pos) {
                l = mid + 1;
                at_stop = mid;
            } else {
                r = mid - 1;
            }
        }
        if (at_stop == -1) { // No other coffee to take while drinking
            dp[i] = R * B + dp[opt[at_start]];
            go[i] = opt[at_start];
        } else {
            // Find optimal position to maybe take a new cup
            int optimal_pos = sgt.get(1, 1, n + 1, at_start, at_stop).second;
            dp[i] = (pos[optimal_pos] - start_pos) + dp[optimal_pos];
            go[i] = optimal_pos;
            // We coull also choose to not take a new cup
            int after_stop = opt[at_stop + 1];
            if (after_stop > 0 && R * B + dp[after_stop] > dp[i]) {
                dp[i] = R * B + dp[after_stop];
                go[i] = after_stop;
            }
        }
        // Find the optimal position to take coffee at i <= pos
        if (dp[opt[i + 1]] > dp[i]) {
            opt[i] = opt[i + 1];
        }
        sgt.update(1, 1, n + 1, i, i, dp[i]);
    }
    vector<int> answer;
    ll ans = 0; int pos = 1;
    for (int i = 1; i <= n; i++) {
        if (dp[i] > ans) {
            ans = dp[i];
            pos = i;
        }
    }
    answer.emplace_back(pos - 1);
    while (1) {
        int new_pos = go[pos];
        if (new_pos == n + 1 || new_pos == 0) break;
        pos = new_pos;
        answer.emplace_back(pos - 1);
    }
    int len = answer.size();
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << answer[i] << (i == len - 1 ? '\n' : ' ');
    }

    return 0;
}