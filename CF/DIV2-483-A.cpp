#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> v(n);
    for(auto &e:v)cin >> e;
    sort(v.begin(),v.end());
    int cnt = 0, i = 0;
    while(cnt < n-1){
        if(cnt&1)i++;
        cnt++;
    }
    cout << v[i] << "\n";


    return 0;
}
