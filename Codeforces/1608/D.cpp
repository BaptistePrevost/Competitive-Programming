/*
    Author : Baptiste Prévost

    Idea : 
        - #BB == #WW
        - We will suppose that we want to reduce the chain to WB or BW
        - If BW, we have #WB>=1 => #BB>=1
*/

#include <iostream>
#include <string>
#include "math.h"
using namespace std;


long long int fact(int n) {
    if(n==0) return 1;
    else return n*fact(n-1);
}

long long int among(int k, int n ){
    // if(k == 0) return 1;
    // if(k > n) return 0;
    // return among(k-1, n-1) + among(k, n-1);

    return fact(n)/fact(n-k);
}


int main() {
    int n;
    int bb=0, bw=0, wb=0, ww=0, ub=0, uw=0, bu=0, wu=0, uu=0;
    string s;
    getline(cin, s);
    n = stoi(s);
    for(int i = 0; i < n; i++) {
        getline(cin, s);
        if(s[0] == 'B' && s[1] == 'B') bb++;
        else if(s[0] == 'B' && s[1] == 'W') bw++;
        else if(s[0] == 'W' && s[1] == 'B') wb++;
        else if(s[0] == 'W' && s[1] == 'W') ww++;
        else if(s[0] == '?' && s[1] == 'B') ub++;
        else if(s[0] == '?' && s[1] == 'W') uw++;
        else if(s[0] == 'B' && s[1] == '?') bu++;
        else if(s[0] == 'W' && s[1] == '?') wu++;
        else uu++;
    }

    long long int ret = 0;

    int to_build = abs(bb-ww);
    long long int ret = 0;

    if(bw>0) {
        if(bb > ww) { //add ww. candidates are uu, uw, wu.
            int k, z;
            for(int i=0; i<=to_build; i++){ //i uw, j wu, k uu
                for(int j=0; j<=to_build-i; j++) {
                    k = to_build-i-j;
                    int f1 = among(i, uw)*among(j, wu)*among(k, uu);

                    for(int bonus=0; bonus<0; bonus++) {
                        for(int x=0; x<=bonus; x++) { //x uw, y wu, z uu
                            for(int y=0; y<=bonus-x; y++) {
                                z = bonus-x-y;
                                int f2 = among(x, uw-i)*among(y, wu-j)*among(z, uu-k);

                            }
                        }
                    }
                }
            }
        } else if (ww > bb) { //add bb, candidates are uu, ub, bu.

            //Then, build same number of bb and ww, and the rest as you want
        } else if(bb>0){
            //Then, build same number of bb and ww, and the rest as you want
        
        } else { //bb == ww == 0 initially
            //build only bw, or at least 1 ww and 1 bb and then what you want
        }

    } else {

    }

    cout << ret << endl;

    return 0;
}