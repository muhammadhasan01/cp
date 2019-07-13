#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    vector<int> cnt(3);
    for(auto e:s)cnt[e-'0']++;
    if(cnt[0] == cnt[1]){
        cout << 2 << "\n";
        cout << s[0] << " " << s.substr(1) << "\n";
    }else{
        cout << 1 << "\n";
        cout << s << "\n";
    }


    return 0;
}
