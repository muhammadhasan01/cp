#include<bits/stdc++.h>
using namespace std;

int n,a,b;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b >> s;
    s += "*";
    if(a > b)swap(a,b);
    int res = a + b;
    int sum = 0;
    for(int i=0;i<=n;i++){
        if(s[i]=='*'){
            int x = sum/2, y = sum - x;
            a = max(a-x,0);
            b = max(b-y,0);
            if(a>b)swap(a,b);
            sum = 0;
        }else{
            sum++;
        }
    }
    cout << res - a - b << "\n";

    return 0;
}
