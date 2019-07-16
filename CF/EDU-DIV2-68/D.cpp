#include<bits/stdc++.h>
using namespace std;

int tc;
long long n,k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while(tc--){
        cin >> n >> k;
        if(n == 0){
            puts("Bob");
        }else if(n == 1 || n == 2){
            puts("Alice");
        }else if(n < k){
            puts(n%3 == 0 ? "Bob" : "Alice");
        }else if(n == k){
            puts("Alice");
        }else if(n > k){
            if(k%3 == 0){
                puts((n%(k+1))%3 == 0 && (n+1)%(k+1) != 0 ? "Bob" : "Alice");
            }else{
                puts(n%3 == 0 ? "Bob" : "Alice");
            }
        }
    }

    return 0;
}
