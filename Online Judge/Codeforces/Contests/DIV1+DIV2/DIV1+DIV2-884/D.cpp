#include <bits/stdc++.h>

using namespace std;

const int K = 26;

void solve() {
    int n;
    cin >> n;
    vector<int> div;
    for (int i = 1; 1LL * i * i <= 1LL * n; i++) {
        if (n % i == 0) {
            div.emplace_back(i);
            int j = n / i;
            if (i != j) {
                div.emplace_back(j);
            }
        }
    }
    sort(div.begin(), div.end());
    string ans(n, 'a');
    vector<int> cnt(K);
    for (int i = 1; i < n; i++) {
        fill(cnt.begin(), cnt.end(), 0);
        for (int d : div) {
            int j = i - d;
            if (j < 0) {
                break;
            }
            int num = (ans[j] - 'a');
            cnt[num]++;
        }
        for (int j = 0; j < K; j++) {
            if (cnt[j] == 0) {
                ans[i] = char(int('a') + j);
                break;
            }
        }
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