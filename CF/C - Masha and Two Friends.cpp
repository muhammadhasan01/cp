#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(i,n) for(int i=0;i<(int)n;i++)
#define forn(i,n) for(int i=1;i<=(int)n;i++)
#define formn(i,n) for(int i=0;i<=(int)n;i++)
#define debug1(i) printf("debug => %ld\n",i);
#define debug2(i,j) printf("debug => %ld - %ld\n",i,j);
#define debug3(i,j,k) printf("debug => %ld - %ld - %ld\n",i,j,k);
#define MEM(a,b) memset(a,(b),sizeof(a))
#define sizearr(arr) sizeof(arr)/sizeof(arr[0])
#define LEN(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

int tc;
ll n,m,x1,y_1,x2,y2,x3,y3,x4,y4,ukuran,putih,hitam;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cin>>n>>m>>x1>>y_1>>x2>>y2>>x3>>y3>>x4>>y4;
        ukuran = n*m;
        putih = ukuran/2;
        if(ukuran&1)putih++;
        hitam = ukuran-putih;
        // putih -> jumlah (x,y) = genap
        if((x2-x1)&1){ // paritas x2 dan x1 berbeda
            //cout << "WTF => ";
            putih += (y2-y_1+1)*(x2-x1+1)/2;
        }else{ // paritas sama
            if((y_1+x1)&1){ // y1 dan x1 beda paritas
                putih += ((y2-y_1+2)/2)*(x2-x1+2)/2;
                putih += ((y2-y_1+1)/2)*(x2-x1)/2;
            }else{ // y1 dan x1 sama paritas
                putih += ((y2-y_1+1)/2)*(x2-x1+2)/2;
                putih += ((y2-y_1+2)/2)*(x2-x1)/2;
            }
        }
        //cout << putih << " ";
        if((x4-x3)&1){ // paritas x2 dan x1 berbeda
            //cout << "WTF => ";
            putih -= (y4-y3+1)*(x4-x3+1)/2;
        }else{ // paritas sama
            if(!((y3+x3)&1)){ // y1 dan x1 beda paritas
                putih -= ((y4-y3+2)/2)*(x4-x3+2)/2;
                putih -= ((y4-y3+1)/2)*(x4-x3)/2;
            }else{ // y1 dan x1 sama paritas
                putih -= ((y4-y3+1)/2)*(x4-x3+2)/2;
                putih -= ((y4-y3+2)/2)*(x4-x3)/2;
            }
        }
        //cout << putih << "\n";
        if((x2 < x3 || y2 < y3) || (x4 < x1 || y4 < y_1)){
            cout << putih << " " << ukuran-putih << "\n";
        }else{
            ll p1,q1,p2,q2;
            if(x2 >= x3){
                p1 = max(x1,x3), p2 = min(x2,x4);
            }else if(x4 >= x1){
                p1 = max(x1,x3), p2 = min(x2,x4);
            }
            if(y2 >= y3){
                q1 = max(y_1,y3), q2 = min(y2,y4);
            }else if(y4 >= y_1){
                q1 = max(y_1,y3), q2 = min(y2,y4);
            }
            //cout << p1 << " " << q1 << " " << p2 << " " << q2 << "\n";
            if((p2-p1)&1){ // paritas x2 dan x1 berbeda
                //cout << "WTF => ";
                putih -= (q2-q1+1)*(p2-p1+1)/2;
            }else{ // paritas sama
                if((q1+p1)&1){ // y1 dan x1 beda paritas
                    putih -= ((q2-q1+2)/2)*(p2-p1+2)/2;
                    putih -= ((q2-q1+1)/2)*(p2-p1)/2;
                }else{ // y1 dan x1 sama paritas
                    putih -= ((q2-q1+1)/2)*(p2-p1+2)/2;
                    putih -= ((q2-q1+2)/2)*(p2-p1)/2;
                }
            }
            cout << putih << " " << ukuran-putih << "\n";
        }
    }

    return 0;
}
