#include<bits/stdc++.h>
using namespace std;

bool get(int x){
    int res = 0;
    while(x != 0){
        res += x%10;
        x/=10;
    }
    return (res%4 == 0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while(!get(n)){
        n++;
    }
    cout << n << '\n';

    return 0;
}
