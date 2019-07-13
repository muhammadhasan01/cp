#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n;
long long m;
long long a[N];

bool can(int x){
    long long sum = 0;
    long long minus = 0;
    for(int i=1;i<=n;i+=x){
        for(int j=i;j<=min(i+x-1,n);j++){
            sum += max((long long)0,a[j] + minus);
        }
        --minus;
    }
    return (sum >= m);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1;i<=n;i++)cin >> a[i];

    sort(a+1,a+1+n,greater<long long>());

    int l = 1, r = n, ans = -1;
    while(l <= r){
        int m = (l+r)>>1;
        if(can(m)){
            ans = m;
            r = m-1;
        }else{
            l = m+1;
        }
    }

    cout << ans << "\n";


    return 0;
}
