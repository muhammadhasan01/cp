#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define inf int_MAX
#define MOD 1000000007
#define MEM(a,b) memset(a,(b),sizeof(a))

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<long long, long long> pll;

// Capitalize Word

int main()
{
    string A; cin >> A;
    if(!isupper(A[0])){
        A[0] = toupper(A[0]);
    }
    cout << A << "\n";
    return 0;
}
