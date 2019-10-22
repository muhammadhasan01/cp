// author : moondemon68
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define LL long long
using namespace std;

int main () {
    //clock_t start = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int p=0;
    for (int i=0;i<s.size();i++) {
        if (s[i]=='L') p--; else p++;
    }
    char a[n+5][n+5];
    for (int i=1;i<=n;i++) {
        string s;
        cin >> s;
        for (int j=1;j<=n;j++) {
            a[i][j]=s[j-1];
        }
    }
    if (p%4==0) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                cout << a[i][j];
            }
            cout << endl;
        }
    } else {
        p%=4;
        if (p<0) p+=4;
        for (int r=1;r<=p;r++) {
            char b[n+5][n+5];
            for (int i=1;i<=n;i++) {
                for (int j=1;j<=n;j++) {
                    b[i][j]=a[n-j+1][i];
                    if (b[i][j]=='^') b[i][j]='>';
                    else if (b[i][j]=='>') b[i][j]='v';
                    else if (b[i][j]=='v') b[i][j]='<';
                    else if (b[i][j]=='<') b[i][j]='^';
                }
            }
            for (int i=1;i<=n;i++) {
                for (int j=1;j<=n;j++) {
                    a[i][j]=b[i][j];
                }
            }
        }
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                cout << a[i][j];
            }
            cout << endl;
        }
    }
    //cerr << fixed << setprecision(3) << (clock()-start)*1./CLOCKS_PER_SEC << endl;
    return 0;
}
