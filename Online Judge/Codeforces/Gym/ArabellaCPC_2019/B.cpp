// author : mastre

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

int t, k, n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while (t--){
        cin >> n >> k;

        if (n-k>1){
            cout << "Kilani" << el;
            continue;
        } else if (n-k==1){
            if (k%2){
                cout << "Ayoub" << el;
            } else{
                cout << "Kilani" << el;
            }
        } else{
            if (k%2){
                cout << "Kilani" << el;
            } else{
                cout << "Ayoub" << el;
            }
        }

    }

    return 0;
}
