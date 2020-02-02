#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int f(int A, int B, int K,int x)
{
    for (int i = 0; i < K; i++){
        x = abs(A*x+B);
        cout << x << " " << i << endl;
    }
    return x;
}
int main()
{
    int m;
    vector<int> v[4];
    for(int i = 0; i < 4; i++){
        cin >> m;
        v.push_back(m);
    }
    cout << f(v[0],v[1],v[2],v[3]);
    return 0;
}
