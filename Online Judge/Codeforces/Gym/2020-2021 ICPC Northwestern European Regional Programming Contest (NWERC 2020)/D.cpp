#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

long long prec[N + 5];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    map<long long, int> mp;
    for (int i = 0; i <= N; i++) {
        prec[i] = 1LL * i * i;
        mp[prec[i]] = i;
    }

    int n;
    cin >> n;
    auto ask = [&](int x, int y) -> long long {
        cout << x << " " << y << endl;
        long long ret;
        cin >> ret;
        return ret;
    };
    for (int it = 0; it < n; it++) {
        long long min_dist = ask(0, 0);
        for (int x = 0; x <= N; x++) {
            long long res = min_dist - prec[x];
            if (res < 0) {
                break;
            }
            if (mp.count(res) == 0) {
                continue;
            }
            long long cur = ask(x, mp[res]);
            if (cur == 0) {
                break;
            }
        }
    }
    
    return 0;
}