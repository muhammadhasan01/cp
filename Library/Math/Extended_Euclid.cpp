#include <bits/stdc++.h>

using namespace std;

// https://cp-algorithms.com/algebra/extended-euclid-algorithm.html

// to find (x,y) pair such that ax + by = gcd(a,b)
long long egcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, b, x, y;
    a = 4, b = 6;
    long long gcd = egcd(a,b,x,y);
    cout << x << " " << y << " " << gcd << "\n";
    // x = -1, y = 1, gcd = 2
    return 0;
}
