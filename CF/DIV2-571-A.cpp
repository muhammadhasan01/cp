#include<bits/stdc++.h>
using namespace std;

int n,m,k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    puts(n <= min(m,k) ? "Yes" : "No");


    return 0;
}
