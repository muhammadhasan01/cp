#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int n;
long long  a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    long long sum = 0, mus = 0;
    for(int i=1;i<=n;i++){
        long long x;
        cin >> x;
        if(x >= 0){
            sum += x;
        }else{
            mus += x;
        }
    }
    cout << sum - mus << '\n';

    return 0;
}
