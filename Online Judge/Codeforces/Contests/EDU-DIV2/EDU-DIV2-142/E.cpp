#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<long long> primes;
bitset<N> notPrime;

vector<pair<long long, int>> getFactors(long long n) {
    vector<pair<long long, int>> factorization;
    for (long long d : primes) {
        if (d * d > n) {
            break;
        }
        int cnt = 0;
        while (n % d == 0) {
            n /= d;
            ++cnt;
        }
        if (cnt > 0) {
            factorization.emplace_back(d, cnt);
        }
    }
    if (n > 1) {
        factorization.emplace_back(n, 1);
    }
    return factorization;
}

vector<pair<long long, int>> getFactors(long long x, long long y) {
    vector<pair<long long, int>> A = getFactors(x);
    vector<pair<long long, int>> B = getFactors(y);
    map<long long, int> mp;
    for (auto [d, cnt] : A) {
        mp[d] += cnt;
    }
    for (auto [d, cnt] : B) {
        mp[d] += cnt;
    }
    vector<pair<long long, int>> ret;
    for (auto [d, cnt] : mp) {
        ret.emplace_back(d, cnt);
    }
    return ret;
}

vector<long long> getDivisors(long long x, long long y) {
    vector<pair<long long, int>> factors = getFactors(x, y);
    vector<long long> divs;
    long long cur = 1;
    function<void(int)> gen = [&](int pos) {
        if (pos == (int) factors.size()) {
            divs.emplace_back(cur);
            return;
        }
        auto [d, cnt] = factors[pos];
        gen(pos + 1);
        long long mul = 1;
        for (int i = 1; i <= cnt; i++) {
            mul = mul * d;
            cur = cur * mul;
            gen(pos + 1);
            cur = cur / mul;
        }
    };
    gen(0);
    sort(divs.begin(), divs.end());
    return divs;
}

void solve() {
    long long n;
    cin >> n;
    long long x, y;
    cin >> x >> y;
    vector<long long> div = getDivisors(x, y);
    int len = div.size();
    long long ans = 0;
    int cnt = 0;
    for (int i = 0, j = 0; i < len; i++) {
        long long d = div[i];
        while (j < len && d / div[j] > n) {
            j++;
        }
        if (j >= len) {
            break;
        }
        if (div[j] > n) {
            break;
        }
        for (int k = j; k <= i; k++) {
            if (div[k] > n) {
                break;
            }
            if (d % div[k] == 0) {
                ans = (ans ^ div[k]);
                ++cnt;
                break;
            }
        }      
    }
    cout << cnt << ' ' << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    notPrime[1] = 1;
    for (int i = 2; i < N; i++) {
        if (notPrime[i] == 1) {
            continue;
        }
        primes.emplace_back(i);
        for (int j = i + i; j < N; j += i) {
            notPrime[j] = 1;
        }
    }
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}