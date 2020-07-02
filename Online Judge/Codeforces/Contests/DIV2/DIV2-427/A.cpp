#include <bits/stdc++.h>

using namespace std;

int s, v1, v2, t1, t2;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> v1 >> v2 >> t1 >> t2;
    int timeOne = 2 * t1 + v1 * s;
    int timeTwo = 2 * t2 + v2 * s;
    if (timeOne < timeTwo) {
        puts("First");
    } else if (timeTwo < timeOne) {
        puts("Second");
    } else {
        puts("Friendship");
    }

    return 0;
}