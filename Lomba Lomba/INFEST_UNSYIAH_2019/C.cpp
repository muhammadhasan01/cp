#include<bits/stdc++.h>
using namespace std;

int main(){

    long long M,C,K,A,B;
    cin>>A>>M>>C>>K>>B;
    if(A<C){
        cout<<"Tidak Mungkin"<<"\n";
    } else {
        if(M-2*C<=0) cout<<"Tidak Mungkin"<<"\n";
        else{
            long long t = M-2*C;
            long long wow = K/t; if(K%t!=0) wow++;
            if(20*wow<=B) cout<<(20*wow)<<"\n";
            else cout<<"Tidak Mungkin"<<"\n";
        }
    }

}
