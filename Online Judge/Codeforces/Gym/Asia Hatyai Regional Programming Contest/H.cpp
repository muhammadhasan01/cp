#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

struct Orang {
  string nama;
  int dd, mm, yy;
  Orang() {}
  Orang(string nama, int dd, int mm, int yy) {
    nama = nama, dd = dd, mm = mm, yy = yy;
  }
  bool operator< (const Orang& other) {
    if(yy > other.yy) return true;
    if(yy < other.yy) return false;
    if(mm > other.mm) return true;
    if(mm < other.mm) return false;
    if(dd > other.dd) return true;
    // if(dd < other.dd) return false;
    return false;
  }
};

Orang get_orang(string s) {
  Orang ret;
  int cek = 0;
  string temp = "";
  for(int i = 0; i < (int)s.length(); i++) {
    if(s[i] == ' ') {
      if(cek == 0) { ret.nama = temp; }
      else if(cek == 1) { ret.dd = stoi(temp); }
      else if(cek == 2) { ret.mm = stoi(temp); }
      else if(cek == 3) { ret.yy = stoi(temp); }
      cek++;
      temp = "";
    } else {
      temp += s[i];
    }
  }
  if(cek == 3) ret.yy = stoi(temp);
  return ret;
}


void solve() {
  int n;
  cin >> n;
  cin.ignore();
  Orang termuda = Orang("hasan", 1, 1, 0);
  Orang tertua = Orang("kamal", 31, 12, 9999);
  for(int i = 0; i < n; i++) {
    string res;
    getline(cin, res);
    Orang now = get_orang(res);
    if(now < termuda) {
      termuda = now;
    }
    if(tertua < now) {
      tertua = now;
    }
  }
  cout << termuda.nama << '\n';
  cout << tertua.nama << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int TC = 1;
  for(int i = 1; i <= TC; i++) {
    solve();
  }
  
  return 0;
}