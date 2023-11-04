#include <bits/stdc++.h>

using namespace std;

map<string, int> mp = {
    {"tourist", 3858},
    {"ksun48", 3679},
    {"Benq", 3658},
    {"Um_nik", 3648},
    {"apiad", 3638},
    {"Stonefeang", 3630},
    {"ecnerwala", 3613},
    {"mnbvmar", 3555},
    {"newbiedmy", 3516},
    {"semiexp", 3481}
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    cout << mp[s] << '\n';
    
    return 0;
}