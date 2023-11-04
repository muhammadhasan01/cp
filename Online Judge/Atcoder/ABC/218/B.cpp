#include <bits/stdc++.h>

using namespace std;

const int K = 26;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> P(K);
    for (auto& p : P) {
        cin >> p;
    }
    for (int i = 0; i < K; i++) {
        char cc = char(int('a') + P[i] - 1);
        cout << cc;
    }
    cout << '\n';

    return 0;
}