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

const int N = 1e6 + 7;

int n, m;
int a[N], b[N];
int gcc;
int mono;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=0;i<n;i++){
        cin >> a[i];
    }
    for (int i=0;i<m;i++){
        cin >> b[i];
    }
    gcc = b[0];
    for (int i=1;i<m;i++){
        gcc = __gcd(gcc, b[i]);
    }
    mono = a[0] % gcc;
    // cout << mono << " " << gcc << el;
    for (int i=1;i<n;i++){
        if (a[i] % gcc != mono){
            cout << "No" << el;
            return 0;
        }
    }
    cout << "Yes" << el;

    return 0;
}
