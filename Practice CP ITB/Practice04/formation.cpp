#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll a,b,c,d,e;scanf("%lld %lld",&a,&b);
    c = a+b; d = sqrt(c);
    while(c%d!=0){d--;}
    e = c/d;
    printf("%lld = %lld x %lld\n",c,d,e);
    printf("%lld\n",2*(d+e));
    return 0;
}
