#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n;
long long a[N];
long long sum = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum += a[i];
    }
    sum = (sum + 1)/2;
    long long res = 0;
    for(int i=1;i<=n;i++){
        res += a[i];
        if(res >= sum){
            cout << i << '\n';
            return 0;
        }
    }


    return 0;
}
