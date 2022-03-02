#include <bits/stdc++.h>

using namespace std;

const long double EPS = 1e-9;
const long double MAX = 1e19;
const int R = 101;

vector<vector<long double>> pre(R);
long double logr[R];

void solve() {
    int rr;
    long long nn, pp;
    cin >> nn >> rr >> pp;
    long double n = nn, p = pp;
    if (p <= n) {
        cout << 0 << '\n';
        return;
    }
    long double X = log2(p / n);
    long long approx = max((long long) ceil(X / logr[rr]), 1LL);
    while (n * pre[rr][approx] + EPS < p) {
        approx++;
    }
    while (approx > 1 && n * pre[rr][approx - 1] + EPS >= p) {
        approx--;
    }
    cout << approx << '\n';
}
 
int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for (int i = 1; i < R; i++) {
        pre[i].emplace_back(1);
        int pw = 0;
        long double r = (1 + ((long double) i) / 100);
        logr[i] = log2(r);
        while (true) {
            pw++;
            long double temp = pre[i][pw / 2] * pre[i][pw / 2];
            if (pw & 1) {
                temp *= r;
            }
            pre[i].emplace_back(temp);
            if (temp > MAX) break;
        }
    }

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case " << t << ": ";
        solve();
    }
    
    return 0;
}