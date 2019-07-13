#include<bits/stdc++.h>
using namespace std;

const int N = 170+5;
int n;
double a[N][N], b[N][N], w[N][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(9);
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> w[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(i == j){
                a[i][j] = w[i][j];
                b[i][j] = 0.0;
            }else{
                a[i][j] = (w[i][j] + w[j][i])/2;
                a[j][i] = a[i][j];
                b[i][j] = w[i][j] - a[i][j];
                b[j][i] = -b[i][j];
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << a[i][j] << " ";
        }cout << '\n';
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << b[i][j] << " ";
        }cout << '\n';
    }


    return 0;
}
