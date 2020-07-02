#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n;
int a[2 * N];
int pos[N][2];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int m = 2 * n;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        for (int t = 0; t < 2; t++) {
            if (pos[a[i]][t] == 0) {
                pos[a[i]][t] = i;
                break;
            }
        }
    }
    int ans = 0;
    for (int it = 1; it <= m * m; it++) {
        bool flag = false;
        int idx = -1;
        for (int i = 1; i < m; i++) {
            if (pos[a[i]][0] == i && pos[a[i]][1] > i + 1) {
                if (pos[a[i + 1]][1] == i + 1 && pos[a[i + 1]][0] < i - 1) {
                    pos[a[i]][0] = i + 1;
                    pos[a[i + 1]][1] = i;
                    swap(a[i], a[i + 1]);
                    flag = true;
                    break;
                } else {
                    idx = i;
                }
            }
        }
        if (flag) {
            ans++;
        } else if (idx != -1) {
            pos[a[idx]][0] = idx + 1;
            pos[a[idx + 1]][1] = idx;
            swap(a[idx], a[idx + 1]);
            ++ans;
        } else {
            break;
        }
    }
    cout << ans << '\n';

    return 0;
}