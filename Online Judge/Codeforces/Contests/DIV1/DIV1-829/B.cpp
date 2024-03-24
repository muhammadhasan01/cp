#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x;
    cin >> n >> x;
    vector<int> cnt(x + 1);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        cnt[val]++;
    }
    for (int val = 1; val < x; val++) {
        if (cnt[val] % (val + 1) != 0) {
            cout << "No" << '\n';
            return 0;
        }
        cnt[val + 1] += cnt[val] / (val + 1);
    }
    cout << "Yes" << '\n';
    
    return 0;
}