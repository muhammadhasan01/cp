#include <bits/stdc++.h>
using namespace std;

void answer(int n, int a, int b){
    int temp = 1, c = 1;
    if(a+b >= n){
        cout << "-1\n";
    }else{
    if(a == 0 && b == 0){
        for(int i = 0; i < n-1; i++){
            cout << 1 << " ";
        }
        cout << 1 << "\n";
    }
    else if(a > 0 && b == 0){
        if(n-a <= 1){
            cout << "-1\n";
        }else{
            cout << 1 << " ";
            for(int i = 0; i < a+1; i++){
                cout << temp;
                if(i!=n-1){
                    cout << " ";
                }else{
                cout << "\n";}
                temp++;
            }
            for(int i = a+1; i < n-1; i++){
                cout << 1;
                if(i!=n-1){
                    cout << " ";
                }else{cout << "\n";}
                }
        }
    }else if(a > 0 && b > 0){
    cout << temp << " ";
    for(int i = 1; i <= b; i++){
        temp *= 2;
        cout << temp << " ";
    }
    for(int i = b+1; i <= a+b; i++){
        temp++;
        cout << temp;
        if(i!=n-1){
            cout << " ";
        }else{
        cout << "\n";}
    }
    for(int i = a+b+1; i < n; i++){
        cout << 1;
        if(i != n-1){
            cout << " ";
        }else{
        cout << "\n";}
    }
    }else if(a == 0 && b > 0){
        for(int i = 0; i < b; i++){
            cout << temp;
            temp *= 2;
            if(i!=n-1){
                cout << " ";
            }else{
            cout << "\n";}
        }
        for(int i = b; i < n; i++){
            cout << temp;
            if(i!=n-1){
                cout << " ";
            }else{
            cout << "\n";}
        }
    }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, a, b;
    cin >> n >> a >> b;
    answer(n,a,b);

    return 0;
}
