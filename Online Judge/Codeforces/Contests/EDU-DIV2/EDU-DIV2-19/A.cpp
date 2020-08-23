#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    vector<int> val;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                val.emplace_back(i);
                n /= i;
            }
        }
    }
    if (n > 1) val.emplace_back(n);
    int len = val.size();
    if (len < k) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < k - 1; i++) {
        cout << val[i] << " ";
    }
    int last = 1;
    for (int i = k - 1; i < len; i++) {
        last *= val[i];
    }
    cout << last << '\n';

    return 0;
}