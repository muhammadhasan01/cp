#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> h(n + 2);
    vector<long long> pre(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        pre[i] = pre[i - 1] + h[i];
    }

    auto getTriangle = [&](int k) -> long long {
        return 1LL * k * (k + 1) / 2;
    };

    auto getRange = [&](int l, int r) -> long long {
        return pre[r] - pre[l - 1];
    };

    auto getRes = [&](int l, int r, int val) -> long long {
        if (l > r) {
            return 0LL;
        }
        int len = r - l + 1;
        long long sum = getRange(l, r);
        long long need = getTriangle(val) - getTriangle(max(0, val - len));
        long long res = sum - need;
        return res;
    };

    vector<long long> dpLeft(n + 2);
    {
        stack<int> st;
        for (int i = 1; i <= n; i++) {
            while (!st.empty()) {
                int j = st.top();
                if (h[j] - j > h[i] - i) {
                    st.pop();
                } else {
                    break;
                }
            }
            int j = st.empty() ? 0 : st.top();
            dpLeft[i] = dpLeft[j] + getRes(j + 1, i - 1, h[i] - 1);
            st.emplace(i);
        }
    }
    vector<long long> dpRight(n + 2);
    {
        stack<int> st;
        for (int i = n; i >= 1; i--) {
            while (!st.empty()) {
                int j = st.top();
                if (h[j] + j > h[i] + i) {
                    st.pop();
                } else {
                    break;
                }
            }
            int j = st.empty() ? n + 1 : st.top();
            dpRight[i] = dpRight[j] + getRes(i + 1, j - 1, h[i] - 1);
            st.emplace(i);
        }
    }
    long long ans = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, dpLeft[i] + dpRight[i] + h[i]);
    }
    cout << ans << '\n';
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