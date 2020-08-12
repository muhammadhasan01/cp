#include <bits/stdc++.h>

using namespace std;

const int N = 35;
const long double PHI = 1.618033988749894848204586834;
const long double eps = 1e-14;

int tc;
long double F[N], G[N];
long double x;

string bin(long long x) {
    if (x <= 1) return to_string(x);
    return bin(x / 2) + bin(x % 2);
}

void solve() {
    // Phi^n = F_(n) Phi + F_(n - 1)
    cin >> x;
    if (x == 1) {
        cout << 1 << '\n';
        return;
    }
    vector<int> answer;
    while (x >= 1) {
        int l = 0, r = 30, at = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            long double val = (mid == 0 ? 1 : F[mid] * PHI + F[mid - 1]);
            if (val <= x) {
                at = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (at == 0)
            x -= 1;
        else
            x -= F[at] * PHI + F[at - 1];
        answer.emplace_back(at);
    }
    while (x > eps) {
        int l = 1, r = N - 1, at = 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (G[mid] <= x) {
                r = mid - 1;
                at = mid;
            } else {
                l = mid + 1;
            }
        }
        answer.emplace_back(-at);
        x -= G[at];
    }
    long long pos = 0, neg = 0;
    for (auto& e : answer) {
        if (e >= 0) {
            pos |= (1LL << e);
        } else {
            e = -e;
            neg |= (1LL << e);
        }
    }
    string s1 = bin(pos);
    string s2 = bin(neg); s2.pop_back();
    reverse(s2.begin(), s2.end());
    if (s2.empty()) {
        cout << s1 << '\n';
    } else {
        cout << s1 << '.' << s2 << '\n';
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    F[1] = F[2] = 1;
    for (int i = 3; i < N; i++) {
        F[i] = F[i - 1] + F[i - 2];
    }
    G[0] = 1, G[1] = PHI - 1;
    for (int i = 2; i < N; i++) {
        G[i] = G[i - 2] - G[i - 1];
    }
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}