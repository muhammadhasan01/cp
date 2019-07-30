#include<bits/stdc++.h>
using namespace std;

long double a,b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    cout << fixed << setprecision(12);
    cout << (b * b - a * a)/(2 * a) << '\n';

    return 0;
}
