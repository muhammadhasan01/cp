#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e9;
int tc;
long long n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<long long> v;
    for (long long i = 1; i < 10; i++) {
        long long cur = i;
        do {
            v.push_back(cur);
            cur = cur * 10 + i;
        } while (cur <= INF);
    }
    sort(v.begin(), v.end());

    cin >> tc;
    while (tc--) {
        cin >> n;
        cout << upper_bound(v.begin(), v.end(), n) - v.begin() << '\n';
    }

    return 0;
}
