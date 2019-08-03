#include<bits/stdc++.h>
using namespace std;

string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int n = s.size();
    if(n < 26){
        puts("-1");
    }else{
        bool flag = false;
        char x = 'a';
        for(int i=0;i<n;i++){
            if(x - s[i] >= 0){
                s[i] = x;
                x++;
            }
            //cerr << i+1 << " => " << x << " => " << (x > 'z') << '\n';
            if(x > 'z'){
                flag = true;
                break;
            }
        }
        cout << (!flag ? "-1" : s) << '\n';
    }

    return 0;
}
