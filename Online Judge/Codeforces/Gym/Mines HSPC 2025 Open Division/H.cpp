#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int x, y, z;
    cin >> x >> y >> z;
    int S = x + y + 2 * z;

    char grade;
    if (S >= 360) grade = 'A';
    else if (S >= 320) grade = 'B';
    else if (S >= 280) grade = 'C';
    else if (S >= 240) grade = 'D';
    else grade = 'F';

    cout << grade << "\n";
    
    return 0;
}