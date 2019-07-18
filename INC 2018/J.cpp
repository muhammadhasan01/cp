#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m;cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int mini = 0, maxi = 0;
    for(int i=0;i<m;i++)mini+=a[i];
    int hasil = n/m, sisa = n%m;
    maxi += a[0];
    for(int i=hasil+sisa;i<n;i+=hasil){
        maxi +=a[i];
    }
    cout << mini << " " << maxi << "\n";
    return 0;
}
