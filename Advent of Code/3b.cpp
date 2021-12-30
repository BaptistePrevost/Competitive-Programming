/*
    Author : Baptiste Prévost

    Idea :
        -
        -
*/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long

int main() {
    char s[12];
    int total=0, count = 0;
    vector<vector <char>> l1, l2, temp;

    while(scanf("%s", s)==1) {
        vector<char> v1, v2;
        forn(i, 12) {
            v1.push_back(s[i]);
            v2.push_back(s[i]);
        }
        l1.push_back(v1);
        l2.push_back(v2);
        total++;
    }

    forn(i, 12) {
        temp.clear();
        count = 0;
        if(l1.size() > 1) {
            forn(j, l1.size()) {
                if(l1[j][i]=='1') {
                    count++;
                }
            }

            printf("L1 size is %i and there are %i 1s\n", l1.size(), count);

            if(count*2>=l1.size()) {
                forn(j, l1.size()) {
                    if(l1[j][i] == '1') temp.push_back(l1[j]);
                }
            } else {
                forn(j, l1.size()) {
                if(l1[j][i] == '0') temp.push_back(l1[j]);             
                }
            }
            l1 = temp;
        }

        temp.clear();
        count = 0;
        if(l2.size()>1) {
            forn(j, l2.size()) {
                if(l2[j][i]=='1') {
                    count++;
                }
            }
            printf("L2 size is %i and there are %i 1s\n", l2.size(), count);
            if(count*2>=l2.size()) {
                forn(j, l2.size()) {
                    if(l2[j][i] == '0') temp.push_back(l2[j]);
                }
            } else {
                forn(j, l2.size()) {
                if(l2[j][i] == '1') temp.push_back(l2[j]);             
                }
            }
            l2 = temp;
        }
    }

    printf("Most : (%i) %s\n", l1.size(), l1.front());
    forn(i, 12) printf("%c", l1.front()[i]);
    printf("\nLease : (%i) %s\n", l2.size(), l2.front());
    forn(i, 12) printf("%c", l2.front()[i]);
    printf("\n");

    return 0;
}
