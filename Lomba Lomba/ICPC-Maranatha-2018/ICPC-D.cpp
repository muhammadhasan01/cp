#include<bits/stdc++.h>
using namespace std;

int maxi(int a, int b){
    if(a > b){
        return a;
    } else {
        return b;
    }
}

int jp(int x[],int memo[], int a,int l){
    int k = l-a;
    cout << k << " " << "ke-berapa yo" << endl;
    if(memo[k]!=-1){
        return memo[k];
    }
    if(k == 0){
        memo[k] = 0;
        cout << memo[k] << " di 0" << endl;
        return 0;
    } else if(k == 1){
        memo[k] = 0;
        cout << memo[k] << " di 1 "<< endl;
        return 0;
    } else if(k == 2){
        memo[k] = x[l-1];
        cout << memo[k] << " di 2" << endl;
        return x[1];
    } else {
        int best = -1;
        cout << jp(x,memo,a+2,l) << " yo " << best << endl;
        best = maxi(best, jp(x,memo,a+2,l)+x[1]);
        best = maxi(best, jp(x,memo,a+3,l)+x[2]);
        cout << jp(x,memo,a+3,l)+x[2] << " hm" << best << endl;
        if(l >= 4){
            best = maxi(best, jp(x,memo,a+4,l)+x[3]);
            cout << jp(x,memo,a+4,l)+x[3] << " eh" << best << endl;
        }
        if(l >= 5){
            best = maxi(best, jp(x,memo,a+5,l)+x[4]);
        }
        if(l >= 6){
            best = maxi(best, jp(x,memo,a+6,l)+x[5]);
        }
        memo[k] = best;
        cout << best << endl;
        return memo[k];
    }
}

int solve(int x[],int l){
    int memo[l+1];
    memset(memo,-1,sizeof(memo));
    return jp(x,memo,0,l);
}

int main () {
    int x[4] = {1,10,3,9};
    cout << solve(x,4) << endl;
}
