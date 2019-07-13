#include <bits/stdc++.h>
using namespace std;

bool custom(char x, char y){
    return x > y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    string a;
    cin >> a;
    int x[4];
    memset(x,0,sizeof(x));
    for(int i = 0; i < n; i++){
        switch(a[i]){
        case '2':
            x[0]+=1;
            break;
        case '3':
            x[0]+=1, x[1]+=1;
            break;
        case '4':
            x[0]+=3, x[1]+=1;
            break;
        case '5':
            x[0]+=3, x[1]+=1, x[2]+=1;
            break;
        case '6':
            x[0]+=4, x[1]+=2, x[2] += 1;
            break;
        case '7':
            x[0]+=4, x[1]+=2, x[2] += 1, x[3] += 1;
            break;
        case '8':
            x[0]+=7, x[1]+=2, x[2] += 1, x[3] += 1;
            break;
        case '9':
            x[0]+=7, x[1]+=4, x[2]+=1, x[3]+=1;
            break;
        }
    }
    string jawab = "";
    if(x[3] > 0){
        for(int i=0;i<x[3];i++){
            jawab+="7";
            x[2]-=1,x[1]-=2,x[0]-=4;
        }
        x[3] = 0;
    }
    if(x[2]>0){
        for(int i=0;i<x[2];i++){
            jawab+="5";
            x[1]-=1,x[0]-=3;
        }
        x[2] = 0;
    }
    if(x[1]>0){
        for(int i=0;i<x[1];i++){
            jawab+="3";
            x[0]-=1;
        }
        x[1] = 0;
    }
    if(x[0]>0){
        for(int i=0;i<x[0];i++){
            jawab+="2";
        }
        x[0] = 0;
    }
    cout << jawab << "\n";
    return 0;
}
