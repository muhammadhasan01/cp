#include<bits/stdc++.h>
using namespace std;

long long a[16];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=1;i<=14;i++){
        cin >> a[i];
    }

    long long ans = 0;
    for(int i=1;i<=14;i++){
        if(a[i] > 0){
            long long res = 0;
            int place = i + a[i]%14;
            long long plus = a[i]/14;
            for(int j=1;j<=14;j++){
                long long temp;
                if(j == i){
                    temp = plus;
                }else{
                    temp = a[j] + plus;
                    if(i < j && j <= place){
                        temp++;
                    }else if(j < i && j <= place - 14){
                        temp++;
                    }
                }
                if(temp%2 == 0)res += temp;
            }
            ans = max(ans, res);
        }
    }

    cout << ans << "\n";



    return 0;
}
