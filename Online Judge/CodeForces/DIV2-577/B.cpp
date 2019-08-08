#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    long long sum = 0, maks = -1;
    for(int i=1;i<=n;i++){
        long long x;
        cin >> x;
        maks = max(maks, x);
        sum += x;
    }

    puts(sum%2 == 0 && sum >= maks * 2 ? "YES" : "NO");

    return 0;
}
