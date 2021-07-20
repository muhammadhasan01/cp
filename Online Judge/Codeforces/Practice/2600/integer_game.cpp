#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<long long> a(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    function<void(long long)> query = [&](long long x) {
        cout << x << endl;
        int ret;
        cin >> ret;
        if (ret == 0) {
            exit(0);
        }
        a[ret - 1] += x;
    };
    cout << "First" << endl;
    query(max({a[0], a[1], a[2]}) - min({a[0], a[1], a[2]}));
	query(3 * max({a[0], a[1], a[2]}) - a[0] - a[1] - a[2]);
	query((max({a[0], a[1], a[2]}) - min({a[0], a[1], a[2]})) / 2);

    return 0;
}