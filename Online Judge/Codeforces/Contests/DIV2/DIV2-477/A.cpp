#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n, s;
int tim[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        tim[i] = x * 60 + y;
    }
    tim[n + 1] = 1e9;
    if (tim[1] > s) {
        cout << 0 << " " << 0 << '\n';
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        int cur = tim[i] + s + 1;
        if (cur + s + 1 <= tim[i + 1]) {
            int hour = cur / 60;
            int minute = cur % 60;
            cout << hour << " " << minute << '\n';
            return 0;
        }
    }

    return 0;
}