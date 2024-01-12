#include <bits/stdc++.h>

using namespace std;

const int B = 30;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int m;
    cin >> m;
    vector<int> cnt(B);

    auto answer = [&](long long w) -> bool {
        for (int i = B - 1; i >= 0; i--) {
            long long two = (1LL << i);
            long long need = min(1LL * cnt[i], w / two);
            w -= need * two;
        }
        return w == 0;
    };

    while (m--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x;
            cin >> x;
            cnt[x]++;
        } else if (tp == 2) {
            int w;
            cin >> w;
            cout << (answer(w) ? "YES" : "NO") << '\n';
        }
    }
    
    return 0;
}