#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    int k;
    cin >> k;
    sort(s.begin(), s.end());
    int x = 1;
    do {
        if (x == k) {
            break;
        }
        x++;
    } while (next_permutation(s.begin(), s.end()));
    cout << s << '\n';

    return 0;
}