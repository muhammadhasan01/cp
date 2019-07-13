#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int n, costs[3][5];
char a[N][N][5];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int t=1;t<=4;t++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin >> a[i][j][t];
            }
        }
    }


    for(int t=1;t<=4;t++){
        int cost = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if((i+j)%2 == 0 && a[i][j][t] == '0'){
                    cost++;
                }else if((i+j)%2 == 1 && a[i][j][t] == '1'){
                    cost++;
                }
            }
        }
        costs[1][t] = cost;
        costs[2][t] = n * n - cost;
    }

    int ans = 1e9;
    ans = min(ans, costs[1][1]+costs[1][2]+costs[2][3]+costs[2][4]);
    ans = min(ans, costs[2][1]+costs[2][2]+costs[1][3]+costs[1][4]);
    ans = min(ans, costs[1][1]+costs[2][2]+costs[1][3]+costs[2][4]);
    ans = min(ans, costs[2][1]+costs[1][2]+costs[2][3]+costs[1][4]);
    ans = min(ans, costs[1][1]+costs[2][2]+costs[2][3]+costs[1][4]);
    ans = min(ans, costs[2][1]+costs[1][2]+costs[1][3]+costs[2][4]);
    cout << ans << "\n";


    return 0;
}
