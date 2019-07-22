#include<bits/stdc++.h>
using namespace std;

int t;

void solve(long long x){

    if(x == 0){
        cout << 1 << " " << 1 << '\n';
        return;
    }

    if(x == 3){
        cout << 2 << " " << 2 << "\n";
        return;
    }

    for(long long i=2;i*i<=x;i++){
        if(x%i == 0 && (i + (x/i))%2 == 0){
            long long n = (i + (x/i))/2;
            long long k = (abs(i - (x/i)))/2;

            long long l = 1, r = n, m = 0;
            while(l <= r){
                long long mid = (l+r)>>1;
                if(n/mid <= k){
                    r = mid - 1;
                    m = mid;
                }else{
                    l = mid + 1;
                }
            }

            if(m != 0 && n * n - (n/m) * (n/m) == x){
                cout << n << " " << m << "\n";
                return;
            }
        }
    }
    cout << -1 << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        long long k;
        cin >> k;
        solve(k);
    }




    return 0;
}
