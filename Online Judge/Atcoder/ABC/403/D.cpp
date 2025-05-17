#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    ll D;
    cin >> N >> D;
    vector<int> A(N);
    int maxA = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        maxA = max(maxA, A[i]);
    }
    if (D == 0) {
        set<int> s;
        for (int x : A) {
            s.insert(x);
        }
        cout << N - (int) s.size() << '\n';
        return 0;
    }
    vector<int> freq(maxA + 1, 0);
    for (int x : A) {
        freq[x]++;
    }
    ll keep = 0;
    for (int v = 0; v <= maxA; v++) {
        if (freq[v] > 0 && (v < D || freq[v - D] == 0)) {
            ll prev2 = 0, prev1 = 0;
            for (int u = v; u <= maxA; u += D) {
                if (freq[u] == 0) {
                    break;
                }
                ll w = freq[u];
                ll cur = max(prev1, prev2 + w);
                prev2 = prev1;
                prev1 = cur;
            }
            keep += prev1;
        }
    }
    cout << N - keep << '\n';
    
    return 0;
}