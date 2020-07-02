#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int q,n;
int x[N][10];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n;
        int bxl = -1e5, bxr = 1e5, byl = -1e5, byr = 1e5;
        for(int i=1;i<=n;i++){
            cin >> x[i][1] >> x[i][2] >> x[i][3] >> x[i][4] >> x[i][5] >> x[i][6];
            if(x[i][3] == 0){
                bxl = max(bxl,x[i][1]);
            }
            if(x[i][4] == 0){
                byr = min(byr,x[i][2]);
            }
            if(x[i][5] == 0){
                bxr = min(bxr,x[i][1]);
            }
            if(x[i][6] == 0){
                byl = max(byl, x[i][2]);
            }
        }
        if(bxl > bxr || byl > byr){
            cout << 0 << '\n';
        }else{
            cout << 1 << " " << bxl << " " << byl << "\n";
        }
    }

    return 0;
}
