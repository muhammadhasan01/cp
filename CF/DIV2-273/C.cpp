#include<bits/stdc++.h>
using namespace std;

vector<long long> v(3);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(),v.end());
    cout << (v[2] >= 2*(v[0] + v[1]) ? v[0] + v[1] : (v[0] + v[1] + v[2])/3) << '\n'; 

    return 0;
}
