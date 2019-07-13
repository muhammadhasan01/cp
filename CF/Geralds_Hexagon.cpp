#include<bits/stdc++.h>
using namespace std;

long long a[10];

long long comp(long long x){
    return x*x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=1;i<=6;i++){
        cin >> a[i];
    }

    cout << comp(a[1] + a[2] + a[6]) - comp(a[2]) - comp(a[4]) - comp(a[6]) << "\n";

    return 0;
}
