#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = make_pair(x, i + 1);
    }
    sort(a.begin(), a.end());
    cout << a[n - 2].second << '\n';
    
    return 0;
}