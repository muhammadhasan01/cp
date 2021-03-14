#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, w;
    cin >> a >> b >> w;
    int dif = b - a;
    w *= 1000;
    int xa = (w / a) * a;
    int difa = w - xa;
    cerr << difa << ' ' << dif << '\n';
    if (difa > dif * (w / a)) {
        cout << "UNSATISFIABLE\n";
        return 0;
    }
    int ansa = (w / a);
    int xb = (w / b) * b;
    int difb = w - xb;
    int ansb = (w / b) + (w % b != 0);
    cout << ansb << ' ' << ansa << '\n';

    return 0;
}