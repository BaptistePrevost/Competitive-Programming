/*
    Author : Baptiste Prévost

    Idea :
        - Basic idea is to perform XOR between a and b. We can 'desynchronize' XOR(a,b) bits
        - Then check whether b is reachable, and if n-XOR(a,b) is a possible smaller path
*/

#include <iostream>
#include <cstdio>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
typedef long long ll;

int n, xorC, zerosA, zerosB;
string a, b;
char c;

int main() {
    int t;
    cin >> t;

    while(t--) {
        cin >> n >> a >> b;
        
        xorC = 0; zerosA=0; zerosB=0;
        forn(i, n) {
            xorC+=(a[i]!=b[i]);
            zerosA+=(a[i]=='0');
            zerosB+=(b[i]=='0');
        }
        if(zerosA!=zerosB && n-zerosA!=zerosB+1) cout << -1 << endl;
        else if(zerosA==zerosB && n-zerosA==zerosB+1) cout << min(xorC, n-xorC) << endl;
        else if(zerosA==zerosB) cout << xorC << endl;
        else cout << n-xorC << endl;
    }

    return 0;
}
