#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int h, w, n;
    cin >> h >> w >> n;
    vector<pair<int, int>> p(n);
    vector<int> X(n), Y(n);
    for (int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i];
        p[i] = make_pair(X[i], Y[i]);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    X.resize(unique(X.begin(), X.end()) - X.begin());
    Y.resize(unique(Y.begin(), Y.end()) - Y.begin());
    for (int i = 0; i < n; i++) {
        auto& [x, y] = p[i];
        int idX = lower_bound(X.begin(), X.end(), x) - X.begin() + 1;
        int idY = lower_bound(Y.begin(), Y.end(), y) - Y.begin() + 1;
        cout << idX << ' ' << idY << '\n';
    }
    
    return 0;
}