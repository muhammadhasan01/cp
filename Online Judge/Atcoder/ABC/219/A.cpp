#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> points = {40, 70, 90};
    int x;
    cin >> x;
    for (int p : points) {
        if (x < p) {
            cout << p - x << '\n';
            return 0;
        }
    }
    cout << "expert" << '\n';

    return 0;
}