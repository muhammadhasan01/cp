#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<bool> done(n + 1);
    done[0] = true;
    long long sum = 0;
    for (int i = n; i >= 1 && k > 0; i--) {
        if (done[i]) {
            continue;
        }
        int bit = 32 - __builtin_clz(i);
        int num = (1 << bit) - 1;
        int chosen = num - i;
        if (done[chosen]) {
            continue;
        }
        k--;
        done[chosen] = true;
        sum += 2LL * num;
    }
    cout << sum << '\n';
    
    return 0;
}