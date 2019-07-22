#include<bits/stdc++.h>
using namespace std;

const int N = 1e2+5;
char a[N];

bool vowel(char x){
    if(x == 'a' || x == 'i' || x == 'u' || x == 'e' || x == 'o' || x == 'y')return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }


    vector<bool> notok(n+3,false);
    for(int i=1;i<=n;i++){
        if(vowel(a[i]) && vowel(a[i+1])){
            notok[i+1] = 1;
        }
    }

    for(int i=1;i<=n;i++){
        if(!notok[i])cout << a[i];
    }cout << '\n';


    return 0;
}
