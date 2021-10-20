// #define MOD 1000000007LL
#define MOD 998244353LL
#define Interactive false // Interactive?
const int N6 = 1000005, N5 = 100005, N3 = 1005;

#pragma region
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long int ll;
#define INF 1e18
#define rep(i, x, n) for (ll i = x; i < n; i++)
#define rev(i, n, x) for (ll i = n; i > x; i--)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define int long long int
#define ff first
#define ss second
#ifndef Interactive
#define Interactive true
#endif
#ifdef mishra
#define debug(x) cerr << " >> " << #x << ": " << x << " ";
#define debugend() cerr << endl;
#define print_time() cerr << endl                                                            \
                          << endl                                                            \
                          << "time: " << 1000 * (clock() / (double)CLOCKS_PER_SEC) << " ms " \
                          << ctime(&currTime)                                                \
                          << endl                                                            \
                          << endl;
#else
#if (Interactive == false)
#define endl "\n"
#endif
#define debug(x) ;
#define debugend() ;
#define print_time() ;
#endif
vector<pair<int, int>> coord = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, -1}, {-1, -1}, {1, 1}, {-1, 1}, {0, 0}};
bool testcases = false;
int file = 1;
void solve();
void set_operations();

signed main(short argc, char *argv[]) // on my IDE argc is always = 2
{
    set_operations();
    auto currTime = time(NULL);
    if (Interactive == false)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int arg = ((argc == 2) ? min((ll)stoi(argv[1]), file) : 0);
    const char *files[] = {"std.txt", "std1.txt", "std2.txt"};

    do
    {
        if (arg)
        {
            freopen(files[arg - 1], "r", stdin);
            // freopen("std2.txt", "w", stdout);
            cerr << "   >>>   >>>   "
                 << "File : " << arg - 1
                 << "   <<<   <<<" << endl;
        }

        int testcase = 1;
        if (testcases)
            cin >> testcase;

        for (int tt = 0; tt < testcase; tt++)
        {
            // cout << "Case #" << tt + 1 << ": ";
            solve();
        }
    } while (--arg > 0);

    print_time();
    return 0;
}
#pragma endregion

// /*
int power(int x, int y)
{
    int res = 1;
    x = x % MOD;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % MOD;
        y = y >> 1;
        x = (x * x) % MOD;
    }
    return res;
}
inline int multi(int a, int b)
{
    return ((a * b) % MOD);
}

//---------------------CODE STARTS HERE---------------------

string ny[2] = {"NO", "YES"};

void set_operations()
{

    // file = 3;
    // sieve();

    // testcases = true;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    bool a[n][m];
    vector<int> f(N5 * 4);
    f[2] = 1;
    for (int i = 2; i < N5 * 4 - 1; i++)
        f[i + 1] = (f[i] + f[i - 1] * 2 + power(2, i - 1)) % MOD;

    // cout << f[3] << endl;
    // cout << f[4] << endl;
    string s;
    int whites = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '*')
                a[i][j] = 1;
            else
                a[i][j] = 0, whites++;
        }
    }
    int ans = 0;
    auto calc = [&](int i) {
        ans = (ans + multi(f[i], power(2, whites - i))) % MOD;
    };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int cnt = 0;
            while (j < m && a[i][j] == 0)
                j++, cnt++;
            if (cnt != 0)
                calc(cnt);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int cnt = 0;
            while (j < n && a[j][i] == 0)
                j++, cnt++;
            if (cnt != 0)
                calc(cnt);
        }
    }
    cout << ans << endl;
}