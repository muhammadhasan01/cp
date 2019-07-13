#include<bits/stdc++.h>
using namespace std;

long long a,b,x,y,z;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> x >> y >> z;
    long long reqa = 2*x + y;
    long long reqb = y + 3*z;

    cout << max((long long)0, reqa - a) + max((long long)0, reqb - b) << "\n";

    return 0;
}
