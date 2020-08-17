#include <bits/stdc++.h>

using namespace std;



int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 1; i <= n; i++) {
        cin >> v[i - 1];
    }
    int T;
    cin >> T;
    for (int it = 0; it < T; it++) {
        int maks = *max_element(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            v[i] = maks - v[i];
            cout << v[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}