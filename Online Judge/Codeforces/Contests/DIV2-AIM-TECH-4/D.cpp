#include <bits/stdc++.h>

using namespace std;

const int M = 1e3 + 5;
const int N = 5e4 + 5;

int p[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    srand(time(NULL));
    int n, start, x;
    cin >> n >> start >> x;
    int cur = -1;
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    random_shuffle(p + 1, p + 1 + n);
    for (int i = 1; i <= min(M, n); i++) {
        cout << "? " << p[i] << endl;
        int res, nxt;
        cin >> res >> nxt;
        if (res < x && res > cur) {
            start = nxt;
            cur = res;
        }
    }
    while (start != -1) {
        cout << "? " << start << endl;
        int res;
        cin >> res >> start;
        if (res >= x) {
            ans = res;
            break;
        }
    }
    cout << "! " << ans << endl; 

    return 0;
}