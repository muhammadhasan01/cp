#include <bits/stdc++.h>

using namespace std;

const int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};
string s;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int x = s[0] - 'a' + 1;
    int y = s[1] - '0';
    int ans = 0;
    for (int it = 0; it < 8; it++) {
        int nx = x + dx[it];
        int ny = y + dy[it];
        if (nx < 1 || nx > 8 || ny < 1 || ny > 8) continue;
        ++ans;
    }
    cout << ans << '\n';

    return 0;
}