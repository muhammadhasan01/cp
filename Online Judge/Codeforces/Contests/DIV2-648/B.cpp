#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int tc;
int n;
pair<int, int> a[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].first;
        }
        int one = 0, two = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].second;
            if (a[i].second == 1) {
                one++;
            } else {
                two++;
            }
        }
        if (one > 0 && two > 0) {
            cout << "Yes" << '\n';
        } else {
            bool flag = true;
            for (int i = 1; i < n; i++) {
                if (a[i].first > a[i + 1].first) {
                    flag = false;
                    break;
                }
            }
            cout << (flag ? "Yes" : "No") << '\n';
        }
    }

    return 0;
}