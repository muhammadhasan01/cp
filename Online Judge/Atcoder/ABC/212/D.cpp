#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    long long sum = 0;
    multiset<long long> ms;
    for (int i = 0; i < n; i++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            long long x;
            cin >> x;
            ms.emplace(x - sum);
        } else if (tp == 2) {
            long long x;
            cin >> x;
            sum += x;
        } else if (tp == 3) {
            assert(!ms.empty());
            long long val = *ms.begin();
            ms.erase(ms.begin());
            cout << val + sum << '\n';
        }
    }
    
    return 0;
}