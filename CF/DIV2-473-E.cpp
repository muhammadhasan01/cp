#include<bits/stdc++.h>
using namespace std;

long long n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int k = log2(n);
    long long mst = 0;
    for(int i=0;i<=k;i++){
        long long c = ((long long)1 << i);
        mst += ((n + c-1)/(2*c)) * c;
    }
    cout << mst << "\n";


    return 0;
}
