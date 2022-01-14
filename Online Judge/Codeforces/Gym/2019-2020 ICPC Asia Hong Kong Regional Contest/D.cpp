#include <bits/stdc++.h>

using namespace std;

void solve() {
    int k;
    long long x;
    cin >> k >> x;
    auto get_pow = [&]() -> vector<long long> {
        vector<long long> ret;
        ret.emplace_back(1);
        while (true) {
            long long b = ret.back();
            if (b > x) {
                break;
            }
            b = (b * k);
            ret.emplace_back(b);
        }
        return ret;
    };
    vector<long long> pows = get_pow();
    long long sum = 0;
    int len = pows.size();
    int pos = -1;
    for (int i = 1; i < len; i++) {
        sum += pows[i];
        if (sum >= x) {
            sum -= pows[i];
            pos = i;
            break;
        }
    }
    assert(pos != -1);
    x = x - sum;
    vector<int> ans(pos, k);
    bool ok = false;
    for (int i = 0; i < pos; i++) {
        int j = pos - i - 1;
        for (int num = 10 - k; num <= 9; num++) {
            if (pows[j] > x) {
                ans[i] = num;
                break;
            } else if (pows[j] == x) {
                ans[i] = num;
                for (int l = i + 1; l < pos; l++) {
                    ans[l] = 9;
                }
                ok = true;
                break;
            }
            x -= pows[j];
        }
        if (ok) {
            break;
        }
    }
    for (int i = 0; i < pos; i++) {
        cout << ans[i];
    }
    cout << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}