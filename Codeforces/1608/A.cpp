/*
    Author : Baptiste Prévost

    Idea : 
        - For every n>2, n doesn't divide n+2
*/

#include <iostream>
#include <list>
using namespace std;


int main() {

    int t, n;
    scanf("%i", &t);
    while(t--) {
        scanf("%i", &n);

        printf("2");
        for(int i = 1; i < n; i++) {
            printf(" %i", i+2);
        }
        printf("\n");
    }

    return 0;
}