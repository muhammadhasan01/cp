#include <bits/stdc++.h>

using namespace std;

string s;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int sumF = 0, sumS = 0;
    for (int i = 0; i < 3; i++) {
        sumF += (int) (s[i] - '0');
    }
    for (int i = 3; i < 6; i++) {
        sumS += (int) (s[i] - '0');
    }
    if (sumF == sumS) {
        cout << 0 << '\n';
        return 0;
    }
    sort(s.begin(), s.begin() + 3);
    sort(s.begin() + 3, s.end());
    int x = 0, y = 3;
    if (sumF > sumS) {
        x = 3, y = 6;
        swap(sumF, sumS);
    }
    vector<int> v;
    for (int i = 0; i < 6; i++) {
        if (x <= i && i <= y) {
            v.emplace_back((int) ('9' - s[i]));
        } else {
            v.emplace_back((int) (s[i] - '0'));
        }
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < 6; i++) {
        sumF += v[i];
        if (sumF >= sumS) {
            cout << i + 1 << '\n';
            return 0;
        }
    }

    return 0;
}