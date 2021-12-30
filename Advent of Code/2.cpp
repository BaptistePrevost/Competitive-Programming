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
    long long int x=0, aim=0, depth=0, n;
    char* s;

    while(scanf("%s %lli", s, &n) == 2) {
        // printf("Read %i\n", n);
        if(s[0]=='f') {
            x += n;
            depth += aim*n;
            }
        else if(s[0]=='u') aim-= n;
        else aim+=n;
    }

    printf("%lli\n", x*depth);

    return 0;
}
