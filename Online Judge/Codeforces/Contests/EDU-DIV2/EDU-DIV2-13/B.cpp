#include <bits/stdc++.h>

using namespace std;

int y;

int isLeap(int x) {
    if (x % 400 == 0) return 1;
    return (x % 4 == 0 && x % 100 != 0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> y;
    int res = isLeap(y);
    int days = 0;
    int x = y + 1;
    while (1) {
        int cur = isLeap(x);
        days += 365 + cur;
        days %= 7;
        if (days == 0 && res == cur) {
            cout << x << '\n';
            return 0;
        }
        x++;
    }
    
    return 0;
}