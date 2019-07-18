#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define inf int_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))
#define el "\n"
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// Equality : http://codeforces.com/contest/1038/problem/A

int a[26];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k; cin >> n >> k;
    string s; cin >> s;
    MEM(a,0);
    for(int i=0;i<s.size();i++){
        a[int(s[i])-65]++;
    }
    int ans = *min_element(a,a+k);
    cout << ans*k << "\n";
    return 0;
}
