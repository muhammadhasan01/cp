#include <bits/stdc++.h>
using namespace std;

long long answer(long long a, long long b){
    if(a == b){
        return 1;
    }
    if(a < b){
        long long temp = a;
        a = b;
        b = temp;
    }
    if(b == 1){
        return a;
    }
    return a/b+answer(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a,b;
    cin >> a >> b;
    cout << answer(a,b) << "\n";
    return 0;
}
