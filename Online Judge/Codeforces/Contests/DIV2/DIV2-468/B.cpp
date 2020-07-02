#include <bits/stdc++.h>

using namespace std;

int n, a, b;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b;
    vector<int> v(n);
    iota(v.begin(), v.end(), 1);
    int round = 1;
    while (n > 1) {
        vector<int> w;
        for (int i = 0; i < n; i += 2) {
            if ((v[i] == a && v[i + 1] == b) || (v[i] == b && v[i + 1] == a)) {
                if (n == 2) {
                    cout << "Final!" << '\n';
                    return 0;
                } else {
                    cout << round << '\n';
                    return 0;
                }
            }
            if (v[i + 1] == a || v[i + 1] == b) {
                w.push_back(v[i + 1]);
            } else {
                w.push_back(v[i]);
            }
        }
        w.swap(v);
        n /= 2;
        ++round;
    }

    return 0;
}