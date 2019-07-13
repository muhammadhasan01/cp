#include <bits/stdc++.h>
using namespace std;

long long answer(long long x){
    if(x==1)return 4;
    if(x==2)return 10;
    if(x==3)return 20;
    if(x==4)return 35;
    if(x==5)return 56;
    if(x==6)return 83;
    if(x==7)return 116;
    if(x==8)return 155;
    if(x==9)return 198;
    if(x==10)return 244;
    if(x==11)return 292;
    return (x-11)*49+292;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long T,N;
    cin >> T;
    while(T--){
        cin >> N;
        cout << answer(N) << "\n";
    }
    return 0;
}
