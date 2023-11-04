#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<bool> red(n + 2);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != 2 || red[i]) {
            continue;
        }
        ++ans;
        red[i] = true;
        for (int j = i - 1; j >= 1; j--) {
            if (a[j] == 0 || red[j]) {
                red[j] = true;
                break;
            }
            red[j] = true;
        }
        for (int j = i + 1; j <= n; j++) {
            if (a[j] == 0 || red[j]) {
                red[j] = true;
                i = j;
                break;
            }
            red[j] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (red[i]) {
            continue;
        }
        if (a[i] == 1) {
            ++ans;
            if (i - 1 >= 1 && !red[i - 1]) {
                red[i - 1] = red[i] = true;
                while (i + 1 <= n && a[i + 1] == 1) {
                    red[i + 1] = true;
                    i++;
                }
            } else {
                red[i] = true;
                while (i + 1 <= n && a[i + 1] == 1) {
                    red[i + 1] = true;
                    i++;
                }
                red[i + 1] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (red[i]) {
            continue;
        }
        ++ans;
    }
    cout << ans << '\n';
    
    return 0;
}