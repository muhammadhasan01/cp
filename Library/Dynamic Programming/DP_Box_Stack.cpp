#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
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
#define SIZE(arr) sizeof(arr)/sizeof(arr[0])
#define LEN(x) (int)x.size()
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

/*

https://www.geeksforgeeks.org/box-stacking-problem-dp-22/
https://practice.geeksforgeeks.org/problems/box-stacking/1

You are given a set of n types of rectangular 3-D boxes
where the i^th box has height h(i), width w(i) and depth d(i) (all real numbers).
You want to create a stack of boxes which is as tall as possible
but you can only stack a box on top of another box
if the dimensions of the 2-D base of the lower box are each strictly larger
than those of the 2-D base of the higher box
*/

/*
Solution :

1) Generate all 3 rotations of all boxes. The size of rotation array
becomes 3 times the size of original array. For simplicity,
we consider depth as always smaller than or equal to width.

2) Sort the above generated 3n boxes in decreasing order of base area.

3) After sorting the boxes, the problem is same as LIS with following optimal substructure property.
MSH(i) = Maximum possible Stack Height with box i at top of stack
MSH(i) = { Max ( MSH(j) ) + height(i) } where j < i and width(j) > width(i) and depth(j) > depth(i).
If there is no such j then MSH(i) = height(i)

4) To get overall maximum height, we return max(MSH(i)) where 0 < i < n

Following is the implementation of the above solution.

*/

struct box{
    // l -> length, w -> width, h -> height
    // WLOG w <= l
    int l, w, h;
};

int tc,n;
box a[103];

bool cmpr(box a, box b){
    return (a.w*a.l > b.w*b.l);
}

ll solve(){

    box rot[3*n+3];
    int idx = 1;
    for(int i=1;i<=n;i++){
        rot[idx].h = a[i].h;
        rot[idx].w = min(a[i].w,a[i].l);
        rot[idx].l = max(a[i].w,a[i].l);
        idx++;

        rot[idx].h = a[i].w;
        rot[idx].w = min(a[i].l,a[i].h);
        rot[idx].l = max(a[i].l,a[i].h);
        idx++;

        rot[idx].h = a[i].l;
        rot[idx].w = min(a[i].w,a[i].h);
        rot[idx].l = max(a[i].w,a[i].h);
        idx++;
    }

    n = 3*n; // the number of boxes is 3*n now
    sort(rot+1,rot+1+n,cmpr);

    ll dp[n+3]; // dp[i] = maximum possible stack height with box i on top
    for(int i=1;i<=n;i++){
        dp[i] = rot[i].h;
        if(i > 1){
            for(int j=1;j<i;j++){
                if(rot[i].w < rot[j].w && rot[i].l < rot[j].l){
                    dp[i] = max(dp[i], rot[i].h + dp[j]);
                }
            }
        }
    }
    return *max_element(dp+1,dp+1+n);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;
    while(tc--){
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a[i].l >> a[i].w >> a[i].h;
        }
        cout << solve() << "\n";
    }

    return 0;
}
