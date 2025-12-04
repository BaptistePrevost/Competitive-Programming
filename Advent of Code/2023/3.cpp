/*
    Author : Baptiste Prévost

    Idea :
        -
        -
*/

#include <iostream>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long

int main() {
    char s[50];
    int total=0, ones[12] = {0,0,0,0,0,0,0,0,0,0,0,0};

    while(scanf("%s", s)==1) {
        total++;
        forn(i, 12) {
            if(s[i]=='1') ones[i]++;
        }
    }

    printf("Gamma rate : ");
    forn(i, 12) {
        if(ones[i]*2>total) printf("1");
        else printf("0");
    }
    printf("\nEpsilon rate : ");
    forn(i, 12) {
        if(ones[i]*2>total) printf("0");
        else printf("1");
    }
    printf("\n");
    return 0;
}
