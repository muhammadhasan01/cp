#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] != a[n - 1]) {
            cout << a[i] << '\n';
            return 0;
        }
    }
    assert(false);
    
    return 0;
}