#include<bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=2;j<=i;j++){
            cout << i << " => " << j << " => " << (i * i) - (i/j) * (i/j) << '\n';
        }
    }

    return 0;
}
