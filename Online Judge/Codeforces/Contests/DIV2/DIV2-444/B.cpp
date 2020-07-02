#include <bits/stdc++.h>

using namespace std;

const int N = 10;

int n;
int a[N][N];
vector<int> num;

void generate(const vector<int>& v, int x, int val) {
    int len = v.size();
    if (x == len) {
        num.emplace_back(val);
        return;
    }
    for (int i = 0; i < 6; i++) {
        generate(v, x + 1, val * 10 + a[v[x]][i]);
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> a[i][j];
        }
    }
    num.emplace_back(0);
    vector<int> v(n);
    iota(v.begin(), v.end(), 0);
    do {
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> bit;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bit.emplace_back(v[i]);
                }
            }
            generate(bit, 0, 0);
        }
    } while (next_permutation(v.begin(), v.end()));
    sort(num.begin(), num.end());
    num.resize(unique(num.begin(), num.end()) - num.begin());
    int ans = 0;
    for (auto& e : num) {
        if (e == ans + 1) {
            ++ans;
        }
    }
    cout << ans << '\n';

    return 0;
}