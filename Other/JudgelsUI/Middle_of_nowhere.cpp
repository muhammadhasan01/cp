#include<bits/stdc++.h>
using namespace std;

int tc;
long double a,b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(9);

    cin >> tc;
    while(tc--){
        cin >> a >> b;
        cout << (b * b)/a << '\n';
    }

    return 0;
}
