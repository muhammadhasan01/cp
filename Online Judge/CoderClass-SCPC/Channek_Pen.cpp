#include<bits/stdc++.h>
using namespace std;

string x[13];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=1;i<=9;i++){
        cin >> x[i];
    }
    int len = x[1].size();
    int cnt = 0;
    for(int j=0;j<len;j++){
        //cerr << j << '\n';
        if(j%5 == 0){
            if(j > 0){
                char k;
                if(cnt == 0){
                    k = ' ';
                }else if(cnt == 18){
                    k = 'A';
                }else if(cnt == 20){
                    k = 'B';
                }else if(cnt == 13){
                    k = 'C';
                }
                cout << k;
                if(j == len-1)cout << '\n';
            }
            cnt = 0;
            continue;
        }
        for(int i=1;i<=9;i++){
            if(x[i][j] == '0')cnt++;
        }
        //cerr << x[1] << '\n';
    }

    return 0;
}
