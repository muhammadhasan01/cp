#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(i,n) for(int i=0;i<(int)n;i++)
#define forn(i,n) for(int i=1;i<=(int)n;i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define msort(x,n) sort(x,x+n)
#define nsort(x,n) sort(x+1,x+(int)n+1)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
// Task : Find c so that a = c (mod b)

// The multiplicative inverse of “a modulo m” exists
// if and only if a and m are relatively prime (i.e., if gcd(a, m) = 1).

int egcd(int a, int b, int &x, int &y){
    if(a == 0){
        x = 0, y = 1; return b;
    }
    int x1, y1, d = egcd(b%a, a, x1, y1);
    x = y1-(b/a)*x1;
    y = x1;
    return d;
}

// Function to find module invers a
// ax+by = 1 => ax = 1 (mod b), so our task is to find x
void modinverse1(int a, int b){
    int x,y;
    int g = egcd(a,b,x,y);
    if(g!=1){
        cout << "Inverse doesn't exist\n";
    }else{
        // b is added to handle negative x
        int res = (x%b+b)%b;
        cout << "Modular multiplicative inverse is " << res << "\n";
    }
}

// if b is prime, then we could use the exponation function
int fastexpo(int x, int y, int p){
    int res = 1;
    x = x%p;
    while(y > 0){
        if(y & 1){
            res = (res*x)%p;
        }
        y >>= 1;
        x = (x*x)%p;
    }
    return res%p;
}

void modinverse2(int a, int b){
    int g = __gcd(a,b);
    if(g != 1){
        cout << "Inverse doesn't exist\n";
    }else{
        cout << "Modular multiplicative inverse is ";
        cout << fastexpo(a,b-2,b) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a = 3, b = 17;
    modinverse1(a,b);
    modinverse2(a,b);
    return 0;
}
