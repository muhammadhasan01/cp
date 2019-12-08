#include <bits/stdc++.h>

using namespace std;

int tc;
long long n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        map<long long, int> m;
        m[0]++, m[1]++;
        for (long long i = 1; i * i <= n; i++) {
            m[n / i]++;
            m[i]++;
        }
        int len = m.size();
        cout << len << '\n';
        auto it = m.begin();
        for (int i = 1; i <= len; i++, it++) {
            cout << it -> first << (i == len ? '\n' : ' ');
        }
    }

    return 0;
}
