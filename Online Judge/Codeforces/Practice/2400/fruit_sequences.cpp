#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int n;
char s[N];
int a[N];
long long dp[N];

long long F(long long x) {
    return x * (x + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        if (s[i] == '0') {
            continue;
        }
        a[i] = a[i - 1] + 1;
    }
    long long ans = 0;
    vector<int> st;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1' && s[i + 1] != '1') {
            while (!st.empty() && a[st.back()] <= a[i]) {
                st.pop_back();
            }
            st.emplace_back(i);
        }
        if (s[i] == '1') {
            dp[i] = F(a[i]);
            int l = 0, r = (int) st.size() - 1, at = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (a[st[mid]] > a[i]) {
                    l = mid + 1;
                    at = st[mid];
                } else {
                    r = mid - 1;
                }
            }
            if (at == -1) {
                dp[i] += 1LL * a[i] * (i - a[i]); 
            } else {
                dp[i] += 1LL * a[i] * (i - a[i] - at);
                dp[i] += (dp[at] - F(a[i]) + 1LL * a[i] * a[i]);
            }
        } else if (s[i] == '0') {
            dp[i] = dp[i - 1];
        }
        ans += dp[i];
    }
    cout << ans << '\n';

    return 0;
}