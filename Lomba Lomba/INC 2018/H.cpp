#include<bits/stdc++.h>
using namespace std;
#define ll long long

long long answer(long long x){
    if(x==0)return 0;
    if(x>0 && x<=2)return 1;
    if(x> 2 && x<=4)return 2;
    if(x> 4 && x<=6)return 3;
    if(x> 6 && x<=8)return 4;
    if(x> 8 && x<=9)return 5;
    long long odd, sisa;
    sisa = x%10;
    odd = ((x-sisa)/10)*5+answer(x/10)+answer(sisa);
    return odd;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long x,y,temp; cin >> x >> y;
    long long odd = answer(y)-answer(x);
    temp = x;
    if(temp%2 == 1){odd++;}else{
        if(temp%10==0){
            while(temp%10==0){
                temp/=10;
            }
            if(temp%2==1){odd++;}
        }
    }
    cout << odd << " " << y-x-odd+1 << "\n";
    return 0;
}
