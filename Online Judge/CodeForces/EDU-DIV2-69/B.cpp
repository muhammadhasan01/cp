#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int n;
int a[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int pos = 0;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i] == n)pos = i;
    }

    int i = pos - 1, j = pos + 1;
    int top = n;
    while(top > 1){
        if(a[i] == top - 1){
            top--;
            i--;
        }else if(a[j] == top - 1){
            top--;
            j++;
        }else{
            break;
        }
    }

    puts(top == 1 ? "YES" : "NO");


    return 0;
}
