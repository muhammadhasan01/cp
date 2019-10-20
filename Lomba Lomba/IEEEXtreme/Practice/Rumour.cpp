#include <bits/stdc++.h>

using namespace std;

int q;
long long a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> a >> b;
        vector<long long> va, vb;
        do {
            va.push_back(a); a /= 2;
        } while (a > 0);
        do {
            vb.push_back(b); b /= 2;
        } while (b > 0);
        int la = va.size(), lb = vb.size();
        int ans = 0;
        sort(vb.begin(), vb.end());
        for (int i = 0; i < la; i++) {
            if (binary_search(vb.begin(), vb.end(), va[i])) {
                int pos = lower_bound(vb.begin(), vb.end(), va[i]) - vb.begin();
                pos = lb - pos - 1;
                ans = i + pos;
                break;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
