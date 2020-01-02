#include <bits/stdc++.h>

// author : mastre
 
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

int a, b;
int x, y;

int kel(int a, int b, int as, int bs){
    return abs(a-as) * 2 + abs(b-bs) * 2;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> x >> y;
    int ans;
    if (a==x){
        cout << kel(a, b, x, y) + 6 << el;
        return 0;
    } else if (b==y){
        cout << kel(a, b, x, y) + 6 << el;
        return 0;
    }

    cout << kel(a, b, x, y) + 4 << el;

    return 0;
}
