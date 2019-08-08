#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int n,k;
char a[N][N];
int f[N][N];

int x = 1, y = 1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j] == '#')continue;
            if(j + k - 1 > n)continue;
            bool ok = true;
            for(int t=j;t<=j+k-1;t++){
                ok &= a[i][t] == '.';
                if(!ok)break;
            }
            if(ok){
                for(int t=j;t<=j+k-1;t++){
                    f[i][t]++;
                }
            }
        }
    }

    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            if(a[i][j] == '#')continue;
            if(i + k -1 > n)continue;
            bool ok = true;
            for(int t=i;t<=i+k-1;t++){
                ok &= a[t][j] == '.';
                if(!ok)break;
            }
            if(ok){
                for(int t=i;t<=i+k-1;t++){
                    f[t][j]++;
                }
            }
        }
    }

    int hm = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(f[i][j] > hm){
                hm = f[i][j];
                x = i, y = j;
            }
        }
    }

    cout << x << " " << y << "\n";


    return 0;
}
