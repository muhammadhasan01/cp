#include <bits/stdc++.h>

using namespace std;

string s;
int k;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> k;
    int len = s.length();
    if (k > len) {
        cout << "impossible" << '\n';
        return 0;
    }
    vector<int> cnt(30);
    for (auto& e : s) {
        cnt[(int) (e - 'a')]++;
    }
    int res = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 0) {
            ++res;
        }
    }
    cout << max(0, k - res) << '\n';

    return 0;
}