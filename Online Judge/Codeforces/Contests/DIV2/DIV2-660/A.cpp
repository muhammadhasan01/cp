#include <bits/stdc++.h>

using namespace std;

int tc;
int n;

void solve() {
    cin >> n;
    vector<int> nums = {6, 10, 14, 15, 21, 22};
    do {
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += nums[i];
        }
        if (sum >= n) continue;
        int rem = n - sum;
        bool flag = true;
        for (int i = 0; i < 3; i++) {
            if (rem == nums[i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "YES" << '\n';
            for (int i = 0; i < 3; i++)
                cout << nums[i] << " ";
            cout << rem << '\n';
            return;
        }
    } while (next_permutation(nums.begin(), nums.end()));
    cout << "NO" << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}