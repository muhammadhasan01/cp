#include<bits/stdc++.h>
using namespace std;

int tc;
long long a,b,c,d;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while(tc--){
        cin >> a >> b >> c >> d;
        cout << d + c - a - b << '\n';
    }

    return 0;
}
