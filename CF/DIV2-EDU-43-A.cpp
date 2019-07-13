#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    bool flag = false;
    for(int i=0;i<n;i++){
        if(s[i] == '1' && !flag){
            flag = true;
        }else if(s[i] == '1' && flag)continue;
        cout << s[i];
    }



    return 0;
}
