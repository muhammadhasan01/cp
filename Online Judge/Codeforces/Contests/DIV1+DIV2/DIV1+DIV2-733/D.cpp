#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    vector<int> freq(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
        freq[a[i]]++;
    }
    vector<int> nums;
    for (int i = 1; i <= n; i++) {
        if (freq[i] == 0) {
            nums.emplace_back(i);
        }
    }
    vector<int> last(n + 1, -1);
    vector<int> positions;
    for (int i = 1; i <= n; i++) {
        if (freq[a[i]] > 1) {
            freq[a[i]]--;
            positions.emplace_back(i);
        } else if (freq[a[i]] == 1) {
            last[a[i]] = i;
        }
    }
    int len = positions.size();
    for (int i = 0; i < len; i++) {
        b[positions[i]] = nums[i];
    }
    vector<int> handle;
    for (int i = 1; i <= n; i++) {
        if (b[i] == i) {
            handle.emplace_back(i);
        }
    }
    int len_h = handle.size();
    if (len_h & 1) {
        int pos = handle.back();
        handle.pop_back();
        len_h--;
        swap(b[pos], b[last[a[pos]]]);
    }
    vector<int> temp = b;
    for (int i = 0; i < len_h; i++) {
        b[handle[i]] = temp[handle[(i + 1) % len_h]];
    }
    int k = 0;
    for (int i = 1; i <= n; i++) {
        k += (a[i] == b[i]);
    }
    cout << k << '\n';
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " \n"[i == n];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}