#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18 + 100;

int q;
long long l, r;
vector<long long> numbers;

long long get(long long x) {
    long long ret = upper_bound(numbers.begin(), numbers.end(), x) - numbers.begin() - 1;
    ret += (long long) sqrt(x);
    return ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (long long i = 2; i * i * i <= INF; i++) {
        long long cur = i * i;
        while (cur <= INF / i) {
            cur = (cur * i);
            long long sq = sqrt(cur);
            if (sq * sq != cur) numbers.push_back(cur);
        }
    }
    sort(numbers.begin(), numbers.end());
    numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());
    cin >> q;
    while (q--) {
        cin >> l >> r;
        cout << get(r) - get(l - 1) << '\n';
    }

    return 0;
}