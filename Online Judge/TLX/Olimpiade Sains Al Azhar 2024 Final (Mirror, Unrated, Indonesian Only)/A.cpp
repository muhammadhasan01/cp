#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e12;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<long long> F = {1, 1};
    {
        int i = 0, j = 1;
        while (1) {
            long long cur = F[i] + F[j];
            if (cur > INF) {
                break;
            }
            F.emplace_back(cur);
            i++, j++;
        }
    }
    long long X;
    cin >> X;
    for (int i = 2; i < (int) F.size(); i++) {
        if (X % F[i] == 0) {
            cout << F[i - 1] * (X / F[i]) << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    
    return 0;
}