#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 10;
int H, W, temp, s = 1;
int a[N+2][N+2];

void floydWarshall(){
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(a[i][j] > a[i][k]+a[k][j]){
                    a[i][j] = a[i][k]+a[k][j];
                }
            }
        }
    }

    // checking negative cycle
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(a[i][j] < 0){
                cout << "It contains negative cycle!\n";
                return;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> H >> W;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> a[i][j];
        }
    }
    return 0;
}
