#include <bits/stdc++.h>

using namespace std;


const int N = 5e5 + 5;
const int B = 2;

int n;
pair<char, int> c[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c[i].first >> c[i].second;
    }
    int onez = (1 << 10) - 1;
    int zero = 0;
    vector<int> temp = {onez, zero};
    for (auto& e : temp) {
        for (int i = 1; i <= n; i++) {
            if (c[i].first == '|') {
                e = (e | c[i].second);
            } else if (c[i].first == '^') {
                e = (e ^ c[i].second);
            } else if (c[i].first == '&') {
                e = (e & c[i].second);
            }
        }
    }
    onez = temp[0];
    zero = temp[1];
    int orrr = 0, xorr = 0, andd = 0;
    for (int it = 9; it >= 0; it--) {
        bool bone = (onez & (1 << it));
        bool bzer = (zero & (1 << it));
        if (bone && bzer) {
            orrr |= (1 << it);
            andd |= (1 << it);
        } else if (!bone && bzer) {
            xorr |= (1 << it);
            andd |= (1 << it);
        } else if (bone && !bzer) {
            andd |= (1 << it);
        } else if (!bone && !bzer) {
            //
        }
    }
    cout << 3 << '\n';
    cout << '|' << " " << orrr << '\n';
    cout << '^' << " " << xorr << '\n';
    cout << '&' << " " << andd << '\n';

    return 0;
}