#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n,q;
    cin >> n >> q;
    while(q--){
        long long x;
        cin >> x;
        while(x%2 == 0){
            long long temp = n - x/2;
            x += temp;
        }
        cout << (x + 1)/2 << "\n";
    }

    return 0;
}
