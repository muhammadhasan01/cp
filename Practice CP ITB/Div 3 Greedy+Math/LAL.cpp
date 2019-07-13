#include <bits/stdc++.h>
using namespace std;

long long answer(long long x){
    if(x <= 2){
        return 1;
    }else{
        if(x%3 == 0){
            return 2*(x/3);
        }else{
            return 2*(x/3)+1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n,k;
    cin >> n;
    while(n--){
    cin >> k;
    cout << answer(k) << "\n";
    }
    return 0;
}
