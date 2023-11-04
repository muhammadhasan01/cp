#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<double> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cout << fixed << setprecision(1) << (n % 2 == 1 ? v[n / 2] : (v[n / 2] + v[n / 2 - 1]) / 2);
    
    return 0;
}