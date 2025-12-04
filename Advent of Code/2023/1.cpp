/*
    Author : Baptiste Prévost

    Idea :
        - ?
*/

#include <iostream>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long

int main() {
    int a, b, res = 0;
    scanf("%i", &a);
    
    while(scanf("%i", &b) == 1) {
        if(b>a) res++;
        a=b;
    }

    printf("%i\n", res);
}
