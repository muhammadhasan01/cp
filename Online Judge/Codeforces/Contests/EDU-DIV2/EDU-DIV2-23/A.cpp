#include <bits/stdc++.h>

using namespace std;

long long x[2], y[2];
long long a, b;

void dismiss() {
    puts("NO");
    exit(0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 0; i < 2; i++) {
        cin >> x[i] >> y[i];
    }
    cin >> a >> b;
    long long dy = abs(y[1] - y[0]);
    long long dx = abs(x[1] - x[0]);
    if (dy % b != 0 || dx % a != 0) dismiss();
    long long req_y = dy / b;
    long long req_x = dx / a;
    cout << ((req_x + req_y) & 1 ? "NO" : "YES") << "\n";

    return 0;
}