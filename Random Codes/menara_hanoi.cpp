#include<bits/stdc++.h>
using namespace std;

struct st{
    int no;
    char cx,cy;
};

vector<st> ans[13];

char c1(char a){
    if(a == 'B')return 'C';
    if(a == 'C')return 'B';
    return 'A';
}

char c2(char a){
    if(a == 'A')return 'B';
    if(a == 'B')return 'A';
    return 'C';
}

void get(int x){
    if(x == 1)return;
    get(x-1);
    for(auto e:ans[x-1]){
        st temp = e;
        temp.cx = c1(temp.cx);
        temp.cy = c1(temp.cy);
        ans[x].push_back(temp);
    }
    st temp;
    temp.no = x, temp.cx = 'A', temp.cy = 'C';
    ans[x].push_back(temp);
    for(auto e:ans[x-1]){
        st temp = e;
        temp.cx = c2(temp.cx);
        temp.cy = c2(temp.cy);
        ans[x].push_back(temp);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    st temp;
    temp.no = 1, temp.cx = 'A', temp.cy = 'C';
    ans[1].push_back(temp);

    get(10);

    int n;
    cin >> n;
    for(auto e:ans[n]){
        cout << e.no << " " << e.cx << " " << e.cy << '\n';
    }

    return 0;
}
