#include <bits/stdc++.h>
using namespace std;

long long answer(long long x){
    stack<long long> s;
    long long hasil = 0;
    long long m = 9;
    if(x==0){return 10;}
    if(1 <= x && x <= 9){
        return x;
    }
    while(x>1 && m!=1){
        if(x%m == 0){
            x/=m;
            s.push(m);
            if(2 <= x && x <=9){
                s.push(x);
                x = 1;
                break;
            }
        }else{
            m--;
        }
    }
    if(x != 1){
        return -1;
    }else{
    while(!s.empty()){
        hasil+=s.top();
        s.pop();
        hasil*=10;}
    }
    return hasil/10;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long T,n;
    cin >> T;
    while(T--){
        cin >> n;
        cout << answer(n) << "\n";
    }
    return 0;
}
