#include<bits/stdc++.h>
using namespace std;

int n,x,y;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x >> y;
    for(int a=0;a<=n;a++){
        for(int b=0;b<=n;b++){
            for(int c=0;c<=n;c++){
                for(int d=0;d<=n;d++){
                    if(a-c == y && b-d == x && a+b+c+d == n){
                        cout << a << " " << b << " " << c << " " << d << "\n";
                        return 0;
                    }
                }
            }
        }
    }

    cout << -1 << "\n";



    return 0;
}
