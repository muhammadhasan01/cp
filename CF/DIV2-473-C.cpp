#include<bits/stdc++.h>
using namespace std;

int n;

void solve(){
    if(n == 7 || n == 6){
        cout << 1 << " " << 2 << "\n";
        cout << 2 << " " << 3 << "\n";
        cout << 2 << " " << 4 << "\n";
        cout << 3 << " " << 5 << "\n";
        cout << 3 << " " << 6 << "\n";
        if(n ==7)cout << 3 << " " << 7 << "\n";
    }else if(n >= 8){
        cout << 1 << " " << 2 << "\n";
        cout << 1 << " " << 3 << "\n";
        cout << 2 << " " << 5 << "\n";
        cout << 2 << " " << 4 << "\n";
        cout << 3 << " " << 6 << "\n";
        cout << 4 << " " << 8 << "\n";
        cout << 4 << " " << 7 << "\n";
        for(int i=9;i<=n;i++){
            cout << 2 << " " << i << "\n";
        }
    }else{
        cout << -1 << "\n";
    }
    for(int i=1;i<=n-1;i++){
        cout << i << " " << i+1 << "\n";
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    solve();



    return 0;
}
