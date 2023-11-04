#include <bits/stdc++.h>

using namespace std;

const int K = 30;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int ans = 0;
    vector<int> valsA(n), valsB(n);
    for (int bit = K; bit >= 0; bit--) {
        vector<int> curA(n), curB(n);
        map<int, int> A, B;
        for (int i = 0; i < n; i++) {
            bool on = a[i] & (1 << bit);
            curA[i] = valsA[i] + (on ? 0 : (1 << bit));
            A[curA[i]]++;
        }
        for (int i = 0; i < n; i++) {
            bool on = b[i] & (1 << bit);
            curB[i] = valsB[i] + (on ? (1 << bit) : 0);
            B[curB[i]]++;
        }
        bool ok = true;
        for (auto [val, cnt] : A) {
            if (B[val] != cnt) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            continue;
        }
        ans += (1 << bit);
        valsA.swap(curA);
        valsB.swap(curB);
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}