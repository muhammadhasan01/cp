#include<bits/stdc++.h>
using namespace std;

const int N = 5e5;
int n;
bitset<N+5> prime;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    prime[1] = 1;
    for(long long i=2;i*i<=N;i++){
        if(prime[i] == 0){
            for(long long j=i*i;j<=N;j+=i){
                prime[j] = 1;
            }
        }
    }

    int m = n;
    while(prime[m] == 1){
        m++;
    }

    cout << m << '\n';

    cout << 1 << " " << n << "\n";
    for(int i=1;i<n;i++){
        cout << i << " " << i+1 << '\n';
    }

    for(int i=1;i<=m-n;i++){
        cout << i << " " << i + n/2 << '\n';
    }


    return 0;
}
