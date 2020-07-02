#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(i,n) for(int i=0;i<(int)n;i++)
#define forn(i,n) for(int i=1;i<=(int)n;i++)
#define debug1(i) printf("debug => %d\n",i);
#define debug2(i,j) printf("debug => %d - %d\n",i,j);
#define debug3(i,j,k) printf("debug => %d - %d - %d\n",i,j,k);
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define msort(x,n) sort(x,x+n)
#define nsort(x,n) sort(x+1,x+(int)n+1)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define sizearr(arr) sizeof(arr)/sizeof(arr[0])
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
// https://www.hackerrank.com/challenges/longest-increasing-subsequent/problem
// Given a sequence of integers, find the length of its longest strictly increasing subsequence.

const int NMAX = 1000*1000;
int a[NMAX+3];
int n;

// Optimal Substructure :
// dp[i] = 1+max(dp[j]) where 0 <= j < i and arr[j] < arr[i]
// dp[i] = 1 if there is no such j exist

// O(N^2) solution
int iterative_dp(){
    int dp[n+3];
    for(int i=1;i<=n;i++){
        dp[i] = 1;
        for(int j=1;j<i;j++){
            if(a[j-1] < a[i-1]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    return *max_element(dp+1,dp+1+n);
}

// O(N Log N) solution
int lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}

int lis(){
    int tail[n+3], len = 1;
    MEM(tail,0);

    tail[0] = a[0];
    for(int i=1;i<n;i++){
        if(a[i] > tail[len-1]){
            // if there is an element bigger than the tail
            // change the tail to that element
            len++;
            tail[len-1] = a[i];
        }else{
            // find wether a[i] is already in the subsequence or not
            auto it = find(tail,tail+len,a[i]);
            if(it != tail+len){
                // if found then continue
                continue;
            }
            // if there is no a[i], then change the tail element to a[i]
            it = upper_bound(tail,tail+len,a[i]);
            *it = a[i];
        }
    }
    return len;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    cout << iterative_dp() << "\n";
    cout << lis() << "\n";


    return 0;
}
