// https://codeforces.com/gym/101549/submission/41468178
#include <bits/stdc++.h>

#include <ext/rope>

#define N 51000
using namespace std;
using namespace __gnu_cxx;
crope version[N], r, str; // Works like a string
char s[N];
rope < char > alternate;
struct Rope {
    void Insert(int pos, char s[]) {
        r.insert(pos, s);
        // alternate.insert(alt.mutuable_begin()+pos,s);
        // char s[n] is inserted from position p.. string cannot be inserted, has to b char array
        //suppose r = "abcd" and char s[] = "xyz",p=2 the r will be r="abxyzcd"
    }
    void Erase(int pos, int c) {
        r.erase(pos, c);
        //Removes c character from the position p
    }
    void Substring(int id, int c) {
        str = r.substr(id, c);
        //Takes c character from p position
    }
    int Count(crope R, char a) {
        int cnt = count(R.begin(), R.end(), a);
        // return how many a is there in r;
        return cnt;
    }
}
rop;
int main() {
    clock_t st = clock();
    int n;
    scanf("%d", & n);
    int vnow = 1;
    int cnt = 0;
    while (n--) {
        int c;
        scanf("%d", & c);
        if (c == 1) {
            int p;
            scanf("%d %s", & p, s);
            p -= cnt;
            rop.Insert(p, s);
            version[vnow++] = r;
        } else if (c == 2) {
            int p, c;
            scanf("%d %d", & p, & c);
            p -= cnt;
            c -= cnt;
            rop.Erase(p - 1, c);
            version[vnow++] = r;
        } else {
            int v, p, c;
            scanf("%d %d %d", & v, & p, & c);
            v -= cnt, p -= cnt, c -= cnt;
            for (int i = p; i < p + c; i++) {
                char ch = version[v][i - 1];
                if (ch == 'c') cnt++;
                printf("%c", ch);
            }
            printf("\n");
        }
    }
    return 0;
}