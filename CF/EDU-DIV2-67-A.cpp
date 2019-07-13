#include<bits/stdc++.h>
using namespace std;

int tc;
long long n,s,t;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while(tc--){
        cin >> n >> s >> t;
        if(s>t)swap(s,t);
        cout << n - s + 1 << '\n';
    }


    return 0;
}
