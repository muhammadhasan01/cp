#include<bits/stdc++.h>
using namespace std;

const int N = 15;
int n;
int a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    pair<int,int> maxi = {-1,10000};
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i] < maxi.second){
            maxi.second = a[i];
            maxi.first = i;
        }
    }
    if(n == 1){
        puts("-1");
    }else if(n == 2 && a[1] == a[2]){
        puts("-1");
    }else{
        cout << 1 << "\n" << maxi.first << "\n";
    }


    return 0;
}
