#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int sum_a = accumulate(a.begin(), a.end(), 0);
    int sum_b = accumulate(b.begin(), b.end(), 0);
    int mini = sum_a;
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {
            continue;
        }
        mini = min(mini, a[i] / b[i]);
    }
    for (int box = mini; box >= 1; box--) {
        if (sum_a % box != 0) {
            continue;
        }
        int col = sum_a / box;
        if (col < sum_b) {
            continue;
        }
        vector<int> minreq(col);
        for (int i = 0, j = 0; i < n; i++) {
            for (int it = 0; it < b[i]; it++) {
                minreq[j++] = i + 1;
                a[i] -= box;
            }
        }
        stack<int> rem;
        for (int i = 0; i < n; i++) {
            for (int it = 0; it < a[i]; it++) {
                rem.emplace(i + 1);
            }
        }
        cout << box << " " << col << '\n';
        for (int i = 0; i < box; i++) {
            vector<int> cur = minreq;
            for (int j = sum_b; j < col; j++) {
                cur[j] = rem.top();
                rem.pop();
            }
            for (int j = 0; j < col; j++) {
                cout << cur[j] << " \n"[j == col - 1];
            }
        }
        return 0;
    }
    
    return 0;
}