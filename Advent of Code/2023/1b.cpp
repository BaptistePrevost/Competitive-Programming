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
    int a, b, c, d, res = 0;

    scanf("%i\n%i\n%i", &a, &b, &c);

    while(scanf("%i", &d)==1) {
        if(b+c+d > a+b+c) res++;
        a=b; b=c; c=d;
    }

    printf("%i\n", res);
    return 0;
}
