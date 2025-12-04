/*
    Author : Baptiste Prévost

    Idea :
        -
        -
*/

#include<bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
typedef long long ll;

int main() {
    int m;
    forn(i,5) {
        forn(j, 5) {
            scanf("%d", &m);
            if(m==1) printf("%d", abs(2-i)+abs(2-j));
        }
    }

    return 0;
}
