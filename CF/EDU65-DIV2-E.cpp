#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define forn(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define nrof(i,j,k) for(int i=(int)j;i>=(int)k;i--)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define len(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define ex exit(0);
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

const int N = 1e6+5;
int n, x;
int a[N];
ll ans;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    vector<int> first(x+1, n+1); vector<int> last(x+1, - 1);
    forn(i,1,n){
        cin >> a[i];
        first[a[i]] = min(first[a[i]], i);
        last[a[i]] = max(last[a[i]], i);
    }

    int left_end = 1, right_start = x;
    int last_left = last[left_end], first_right = first[right_start];
    while(left_end < x && first[left_end + 1] > last_left){
        left_end++;
        last_left = max(last_left, last[left_end]);
    }

    while(right_start > 1 && last[right_start - 1] < first_right){
        right_start--;
        first_right = min(first_right, first[right_start]);
    }

    cerr << left_end << " and " << right_start << "\n";

    // the array is already sorted
    if(left_end == x){
        cout << (ll)x * (ll)(x+1)/2 << "\n";
        exit(0);
    }

    int pointer = 1;
    ans += left_end + 1; // because less than left_end will always work
    forn(i,2,left_end)last[i] = max(last[i], last[i-1]);
    nrof(i,x-1,right_start)first[i] = min(first[i], first[i+1]);
    forn(i,right_start,x){
        while(pointer <= left_end && last[pointer] < first[i])
            pointer++;
        ans += pointer;
    }

    cout << ans << "\n";


    return 0;
}
