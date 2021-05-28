#include <bits/stdc++.h>

using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
    public:
        template<class T> explicit y_combinator_result(T && fun): fun_(forward<T> (fun)) {}
    template<class...Args> decltype(auto) operator()(Args &&...args) {
        return fun_(ref(*this), forward<Args>(args)...);
    }
};

template<class Fun> decltype(auto) y_combinator(Fun && fun) {
    return y_combinator_result<decay_t<Fun>>(forward<Fun>(fun));
}

void solve() {
    int n, c, m;
    cin >> n >> c >> m;
    vector<int> b(n);
    vector<double> p(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i] >> p[i];
        p[i] /= 100.0;
    }
    vector<vector<double>> memo(c + 1, vector<double>((1 << n), -1.0));

    auto prob = y_combinator([&](auto self, int bribe, int mask, int money) -> double {
        if (bribe == 0) {
            return 1;
        }
        if (memo[bribe][mask] != -1) {
            return memo[bribe][mask];
        }
        double maks = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) continue;
            if (money < b[i]) continue;
            double success = (double) p[i] * self(bribe - 1, (mask | (1 << i)), money - b[i]);
            double fail = (double) (1 - p[i]) * self(bribe, (mask | 1 << i), money - b[i]);
            maks = max(maks, success + fail);
        }
        return memo[bribe][mask] = maks;
    });
    
    cout << fixed << setprecision(6) << prob(c, 0, m) << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}