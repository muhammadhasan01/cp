#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<int> w;
    for (int i = 0, j = n - 1; i < n; i++, j--) {
        w.emplace_back(v[i]);
        if (i == j) break;
        w.emplace_back(v[j]);
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            if (i % 2 == 0 && w[i] > w[i - 1])
                ok = false;
            else if (i % 2 == 1 && w[i] < w[i - 1]) 
                ok = false;
        }
    }
    if (!ok) {
        cout << "Impossible" << '\n';
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cout << w[i] << (i == n - 1 ? '\n' : ' ');
    }

    return 0;
}