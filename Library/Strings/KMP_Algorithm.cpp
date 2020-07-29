#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define inf INT_MAX
#define MOD 1000000007
#define form(i,n) for(int i=0;i<(int)n;i++)
#define forn(i,n) for(int i=1;i<=(int)n;i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define msort(x,n) sort(x,x+n)
#define nsort(x,n) sort(x+1,x+(int)n+1)
#define MEM(a,b) memset(a,(b),sizeof(a))
#define ll long long
#define pll pair<long long,long long>
#define pii pair<int,int>
using namespace std;

// https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
// https://www.hackerrank.com/challenges/kmp-fp/problem

// Fills lps[] for given patttern pat[0..M-1]
void computeLPS(string pat, int M, int lps[]){

    int len = 0; // length of the previous longest prefix sum
    lps[0] = 0; // lps[0] is always zero

    // the loop calculates lps[i] for i = 1 to M-1
    int i=1;
    while(i<M){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if(len != 0){
                len = lps[len-1];

                // note that i was not incremented
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

// other way
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n,0);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

// Prints occurrences of txt[] in pat[]
void KMPSearch(string pat, string txt){
    int M = pat.size();
    int N = txt.size();

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M+3];

    // preprocess the pattern (calculates lps[] array)
    computeLPS(pat,M,lps);

    for(int i=0;i<M;i++)cout << lps[i] << "\n";

    int i = 0; // index for txt
    int j = 0; // index for pat
    while(i < N){
        if(pat[j] == txt[i]){
            i++;
            j++;
        }
        if(j == M){
            cout << "Found pattern at index " << i-j << "\n";
            j = lps[j-1];
        }

        // mismatch after j matches
        else if(i < N && pat[j] != txt[i]){
            // Do not match lps[0...lps[j-1]] charactes,
            // they will match anyway
            if(j!=0){
                j = lps[j-1];
            }else{
                i++;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string text = "13453457293043";
    string pat = "45345";
    KMPSearch(pat,text);

    return 0;
}
