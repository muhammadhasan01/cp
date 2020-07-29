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

// https://www.geeksforgeeks.org/bits-manipulation-important-tactics/

// Compute XOR from 1 to n (direct method)
int compute_one_to_n(int n){
    if(n%4 == 0){
        return n;
    }
    if(n%4 == 1){
        return 1;
    }
    if(n%4 == 2){
        return n+1;
    }
    if(n%4 == 3){
        return 0;
    }
}


// Given a positive integer n, find count of positive integers i such that 0 <= i <= n and n+i = n^i
int equal_sum_and_xor(int n){
    int k = 0; // count of zero bits
    while(n > 0){
        if(n%2 == 0)k++;
        n/=2;
    }
    return pow(2,k);
}

// knowing if a number is a power of two
bool is_power_of_two(int n){
    return n && (!(n&(n-1)));
}

// Convert binary code directly into an integer in C++
void converter(){
    auto number = 0b011;
    cout << number << "\n";
}

// quickest way to swap two number
void swap(int &n, int &m){
    n ^= m;
    m ^= n;
    n ^= m;
}

// finding the most significant set bit
int set_bit_number1(int n){
    // Below steps set bits after
    // MSB (including MSB)

    // Suppose n is 273 (binary
    // is 100010001). It does following
    // 100010001 | 010001000 = 110011001
    n |= n>>1;

    // This makes sure 4 bits
    // (From MSB and including MSB)
    // are set. It does following
    // 110011001 | 001100110 = 111111111
    n |= n>>2;

    n |= n>>4;
    n |= n>>8;
    n |= n>>16;

    // Increment n by 1 so that
    // there is only one set bit
    // which is just before original
    // MSB. n now becomes 1000000000
    n = n + 1;

    // Return original MSB after shifting.
    // n now becomes 100000000
    return (n >> 1);
}

int set_bit_number2(int n)
{
    // To find the position
    // of the most significant
    // set bit
    int k = (int)(log2(n));

    // To return the the value
    // of the number with set
    // bit at k-th position
    return (int)(pow(2, k));
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    return 0;
}
