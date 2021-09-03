#include <bits/stdc++.h>

using namespace std;

const int K = 32;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    auto ask_or = [&](int i, int j) -> int {
        cout << "or " << i << ' ' << j << endl;
        int ret;
        cin >> ret;
        return ret;
    };
    auto ask_and = [&](int i, int j) -> int {
        cout << "and " << i << ' ' << j << endl;
        int ret;
        cin >> ret;
        return ret;
    };
    vector<int> ors(n + 1), ands(n + 1);
    for (int i = 2; i <= n; i++) {
        ors[i] = ask_or(1, i);
        ands[i] = ask_and(1, i);
    }
    vector<bool> bits(K);
    for (int x : {ands[2]}) {
        for (int i = 0; i < K; i++) {
            bool b = x & (1 << i);
            if (b) {
                bits[i] = true;
            }
        }
    }
    int o23 = ask_or(2, 3);
    for (int x : {ors[2]}) {
        for (int i = 0; i < K; i++) {
            if (bits[i]) {
                continue;
            }
            bool b = x & (1 << i);
            if (!b) {
                continue;
            }
            bool on13_and = ands[3] & (1 << i);
            if (on13_and) {
                bits[i] = true;
                continue;
            }
            bool on13_or = ors[3] & (1 << i);
            if (!on13_or) {
                continue;
            }
            bool on23_or = o23 & (1 << i);
            if (!on23_or) {
                bits[i] = true;
                continue;
            }
        }
    }
    vector<vector<bool>> res(n + 1, vector<bool>(K));
    res[1] = bits;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < K; j++) {
            if (bits[j]) {
                bool b = ands[i] & (1 << j);
                if (b) {
                    res[i][j] = true;
                }
            } else {
                bool b = ors[i] & (1 << j);
                if (b) {
                    res[i][j] = true;
                }
            }
        }
    }
    vector<int> a(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < K; j++) {
            if (res[i][j]) {
                a[i - 1] |= (1 << j);
            }
        }
    }
    sort(a.begin(), a.end());
    cout << "finish " << a[k - 1] << endl;
    
    return 0;
}