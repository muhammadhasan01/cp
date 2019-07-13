#include<bits/stdc++.h>
using namespace std;

int n;
long long l,r;

string bin(long long x){
    if(x == 0)return "0";
    if(x == 1)return "1";
    return bin(x/2) + bin(x%2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while(n--){
        cin >> l >> r;
        string b = bin(r), a = bin(l);
        int nb = b.size(), na = a.size();
        if((r == ((long long)1<<nb) - 1) || l == r){
            cout << r << "\n";
        }else if(nb>na){
            cout << ((long long)1<<(nb-1)) - 1 << "\n";
        }else{
            long long ans = 0;
            int cnt = 0;
            for(auto e:b)if(e == '1')cnt++;
            int len = 0, cnt2 = 0;
            for(int i=0;i<na;i++){
                if(b[i] == '1' && a[i] == '0'){
                    len = na - 1 - i;
                    ans += ((long long)1 << len) - 1;
                    cnt2 += len;
                    break;
                }else if(b[i] == '1'){
                    ans += ((long long)1 << (na-i-1));
                    cnt2++;
                }
            }
            if(cnt > cnt2){
                cout << r << "\n";
            }else{
                cout << ans << "\n";
            }
        }
    }


    return 0;
}
