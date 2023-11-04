#include <bits/stdc++.h>

using namespace std;

const int K = 4;
const int DX[] = {0, 0, 1, -1};
const int DY[] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int R, C;
    cin >> R >> C;
    int rs, cs, rc, cc;
    cin >> rs >> cs >> rc >> cc;
    char player;
    cin >> player;
    if (rs == rc && cs == cc) {
        cout << 'T' << '\n';
        return 0;
    }
    cout << player << '\n';
    
    return 0;
}