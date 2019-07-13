#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<char> v;
    v.push_back('b'); v.push_back('c');
    for(int i=0;i<v.size();i++){cout << v[i];}cout<<"\n";
    v.insert(v.begin()+1,'a');
    for(int i=0;i<v.size();i++){cout << v[i];}cout<<"\n";
    return 0;
}
