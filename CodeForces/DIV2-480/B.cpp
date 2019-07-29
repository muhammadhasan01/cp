#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int n,k;
char a[5][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    if(k%2 == 0){
        cout << "YES" << '\n';
        for(int i=1;i<=4;i++){
            for(int j=1;j<=n;j++){
                if(2 <= i && i <= 3 && 2 <= j && j <= n-1 && j <= k/2 + 1){
                    cout << '#';
                }else{
                    cout << '.';
                }
            }cout << '\n';
        }
    }else if(k == n-2){
        cout << "YES" << '\n';
        for(int i=1;i<=4;i++){
            for(int j=1;j<=n;j++){
                if(i == 2 && 2 <= j && j <= n-1){
                    cout << '#';
                }else{
                    cout << '.';
                }
            }cout << '\n';
        }
    }else if(k%2 == 1 && k > n-2){
        k -= n;
        if(k < 0){
            cout << "NO" << '\n';
            return 0;
        }
        cout << "YES" << '\n';
        for(int i=1;i<=4;i++){
            for(int j=1;j<=n;j++){
                if(i == 2 && 2 <= j && j <= n-1){
                    cout << '#';
                }else if(i == 3 && j == n-1){
                    cout << "#";
                }else if(i == 3 && j == 2){
                    cout << "#";
                }else if(i == 3 && 2 <= j && j <= n-1 && k > 0){
                    cout << '#';
                    k--;
                }else{
                    cout << '.';
                }
            }cout << '\n';
        }
    }else if(k%2 == 1 && n%2 == 1){
        cout << "YES" << '\n';
        vector<bool> huh(n+3,false);
        for(int j=(n+1)/2,z=(n+1)/2,i=0;i<=(k-1)/2;i++,j++,z--){
            huh[j] = 1;
            huh[z] = 1;
        }
        for(int i=1;i<=4;i++){
            for(int j=1;j<=n;j++){
                if(i == 2 && huh[j]){
                    cout << "#";
                }else{
                    cout << ".";
                }
            }cout << '\n';
        }
    }else{
        cout << "NO" << '\n';
    }


    return 0;
}
