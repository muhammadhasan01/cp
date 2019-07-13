#include <bits/stdc++.h>
using namespace std;

bool custom(long long a, long long b){
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    cin >> n;
    long long a[n];
    for(long long i=0;i<n;i++){
        cin >> a[i];}
    sort(a,a+n,custom);
    if(n==1){
        cout << a[0] << "\n";
        return 0;
    }
    long long sum = 0, c = n;
    sum += c*a[0];
    for(long long i = 1; i < n; i++){
        sum += c*a[i];
        c -= 1;
    }
    cout << sum << "\n";
    return 0;
}
