#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> a(4);
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    do {
        if (abs(a[0] - a[1]) != abs(a[2] - a[3])) continue;
        if (abs(a[1] - a[2]) != abs(a[0] - a[3])) continue;
        puts("YES");
        return 0;
    } while (next_permutation(a.begin(), a.end()));
    puts("NO");

    return 0;
}