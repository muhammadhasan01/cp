#include<bits/stdc++.h>
using namespace std;

const int N = 5e4+5;
long long n;
long long pre[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    string s = to_string(n);
    int ns = s.size();
    int len = 0;
    for(long long i=1;i*i<=n;i++){
        pre[++len] = i*i;
    }
    if(pre[len] == n){
        puts("0");
        return 0;
    }else{
        for(int i=len;i>=1;i--){
            bool flag = false;
            string k = to_string(pre[i]);
            int nk = k.size();
            for(int i=0,j=0;i<ns;i++){
                if(s[i] == k[j])j++;
                if(j == nk){
                    flag = true;
                    break;
                }
            }
            if(flag){
                cout << ns - nk << '\n';
                return 0;
            }
        }
    }

    cout << -1 << "\n";



    return 0;
}
