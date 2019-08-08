#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (b > a){
        int temp = a;
        a = b;
        b = temp;
    }
    if(b == 0){
        return a;
    } else {
        return gcd(b,a%b);
    }
}
int kpk(int a, int b){
 return a*b/gcd(a,b);
}
int main()
{
    int inp;
    cin >> inp;
    int x[inp];
    int n;
    for(int i = 0; i < inp; i++){
        cin >> x[i];
        if(i == 1){
            n = kpk(x[i],x[i-1]);
        } else if(i > 1){
            n = kpk(n,x[i]);
        }
    }
    cout << n << endl;
    return 0;
}
