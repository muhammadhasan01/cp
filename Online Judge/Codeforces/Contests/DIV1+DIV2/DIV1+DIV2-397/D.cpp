#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    auto dismiss = [&]() {
        cout << -1 << '\n';
        exit(0);
    };

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> nums;
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        int j = a[i];
        if (a[j] != j) {
            dismiss();
        }
        if (a[i] == i) {
            nums.emplace_back(i);
            ans[i] = nums.size();
        }
    }
    int m = nums.size();
    cout << m << '\n';
    for (int i = 1; i <= n; i++) {
        cout << ans[a[i]] << " \n"[i == n];
    }
    for (int i = 1; i <= m; i++) {
        cout << nums[i - 1] << " \n"[i == m];
    }
    
    return 0;
}