#include<bits/stdc++.h>
using namespace std;

int tc;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while(tc--){
        unsigned long long a,b;
        cin >> a >> b;
        if(a%2 == b%2){
            if(a > b){
                puts("Tere");
            }else if(a < b){
                puts("Toni");
            }else{
                puts("Voting Ulang");
            }
        }else{
            if(a && b){
                if(a-1 > b){
                    puts("Tere");
                }else if(b-1 > a){
                    puts("Toni");
                }else{
                    puts("Voting Ulang");
                }
            }else if(a){
                if(a > 1)puts("Tere");
                else puts("Voting Ulang");
            }else if(b){
                if(b > 1)
                puts("Toni");
                else puts("Voting Ulang");
            }else{
                puts("Voting Ulang");
            }
        }
    }

    return 0;
}
