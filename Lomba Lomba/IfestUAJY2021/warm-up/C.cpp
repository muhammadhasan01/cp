#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    getline(cin, str);
    stringstream ss(str);
    vector<int> nums;
    while (ss >> str) {
        nums.emplace_back(stoi(str));
    }
    vector<pair<int, int>> ans;
    int len = nums.size();
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (abs(nums[j] - nums[i]) == 1) {
                ans.emplace_back(min(nums[i], nums[j]), max(nums[i], nums[j]));
            }
        }
    }
    for (auto& e : ans) {
        cout << e.first << " " << e.second << '\n';
    }

    return 0;
}