#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    // If we can remove everyone, no groups are needed
    if (K >= N) {
        cout << 0;
        return 0;
    }

    int R = K + 1;
    // next_end[l][r]: from starting index l, with at most r removals, the farthest end index (exclusive)
    vector<int> next_end((N + 1) * R);
    vector<int> freq(N + 1);

    // Precompute using sliding-window for each allowed removal r
    for (int allowed = 0; allowed <= K; allowed++) {
        fill(freq.begin(), freq.end(), 0);
        int remCount = 0;
        int end = 0;
        for (int l = 0; l <= N; l++) {
            // extend 'end' while we can include H[end] within 'allowed' removals
            while (end < N) {
                int x = H[end];
                int extra = (freq[x] + 1 > M) ? 1 : 0;
                if (remCount + extra > allowed) break;
                freq[x]++;
                remCount += extra;
                end++;
            }
            next_end[l * R + allowed] = end;
            // before moving l forward, remove H[l] from the window if it was included
            if (l < end) {
                int x = H[l];
                if (freq[x] > M) remCount--;
                freq[x]--;
            } else {
                // window empty -> keep pointers in sync
                end = l + 1;
            }
        }
    }

    // dp[r]: farthest covered index using some number of segments and r removals
    vector<int> dp(R), dpNext(R);
    // base: 1 group
    for (int rem = 0; rem <= K; rem++) {
        dp[rem] = next_end[rem];  // row 0: start at index 0
    }
    if (dp[K] >= N) {
        cout << 1;
        return 0;
    }

    // try adding more groups until we cover all N
    for (int seg = 2; seg <= N; seg++) {
        for (int rem = 0; rem <= K; rem++) {
            int best = 0;
            for (int used = 0; used <= rem; used++) {
                int covered = dp[used];
                int cand = next_end[covered * R + (rem - used)];
                if (cand > best) best = cand;
            }
            dpNext[rem] = best;
        }
        dp.swap(dpNext);
        if (dp[K] >= N) {
            cout << seg;
            return 0;
        }
    }
    // fallback (shouldn't happen): worst case one-person groups
    cout << N;
    return 0;
}
