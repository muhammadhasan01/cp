#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;

    auto outputAnswer = [&](vector<int>& x) -> void {
        cout << "! ";
        for (int i = 1; i <= n; i++) {
            cout << x[i];
            if (i == n) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    };

    vector<int> x(n + 1, -1);
    if (k == 1) {
        for (int i = 1; i <= n; i++) {
            cout << "? " << i << endl;
            cin >> x[i];
        }
        outputAnswer(x);
        return 0;
    }

    auto ask = [&](vector<int>& a) -> int {
        int len = (int) a.size();
        assert(len == k);
        cout << "? ";
        for (int i = 0; i < len; i++) {
            cout << a[i];
            if (i == len - 1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
        int ret;
        cin >> ret;
        return ret;
    };

    {
        vector<int> cur(k + 2, 1);
        vector<int> val(k + 2);
        int parity = 0;
        cur[k + 1] = 0;
        for (int rep = 1, pos = k + 1; rep <= k + 1; rep++, pos--) {
            vector<int> a;
            for (int i = 1; i <= k + 1; i++) {
                if (cur[i]) {
                    a.emplace_back(i);
                }
            }
            val[rep] = ask(a);
            parity = (parity ^ val[rep]);
            swap(cur[pos - 1], cur[pos]);
        }
        for (int rep = 1, pos = k + 1; rep <= k + 1; rep++, pos--) {
            x[pos] = (parity ^ val[rep]);
        }
    }
    int backParity = 0;
    for (int i = 1; i <= k - 1; i++) {
        backParity = (backParity ^ x[i]);
    }
    vector<int> a(k);
    iota(a.begin(), a.end(), 1);
    for (int i = k + 2; i <= n; i++) {
        a[k - 1] = i;
        int cur = ask(a);
        x[i] = (cur ^ backParity);
    }
    outputAnswer(x);
    
    return 0;
}