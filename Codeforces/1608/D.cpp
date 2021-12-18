/*
    Author : Baptiste Prévost

    Idea : 
        - For each correct coloring, there must be in total n white cells, and n black cells => Necessary condition, but not sufficient
        - Counting these coloring is relatively simple. We must now substract the number of incorrect colorings among them.
        - Only possible colorings are with no BB or WW domino, and both WB and BW dominoes 
*/

#include <iostream>
#include <string>
#include <map>
#include <utility>
#include "math.h"
using namespace std;

map<int, map<int, long long int> > mem;

long long int among(int k, int n ){ // Have to perform memoïsation here ...
    if(k == 0) return 1;
    if(k > n) return 0;
    long long int a, b;
    if(mem[k-1][n-1]) a = mem[k-1][n-1];
    else a = among(k-1, n-1);
    if(mem[k][n-1]) b = mem[k-1][n-1];
    else b = among(k, n-1);
    
    long long ret = (a+b)%998244353;
    mem[k][n] = ret;
    return ret;
}

long long int fastPow(long long int base, long long int power) {
        long long result = 1;
    while(power > 0) {

        if(power % 2 == 1) { // Can also use (power & 1) to make code even faster
            result = (result*base) % 998244353;
        }
        base = (base * base);
        power = power / 2; // Can also use power >>= 1; to make code even faster
    }
    return result;
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


    int total_black = 2*bb + wb + bw + ub + bu;
    int total_white = 2*ww + wb + bw + uw + wu;

    if(total_black > n || total_white > n) {
        cout << 0 << endl;
    } else {
        long long int ret = among(n - total_white, 2*n - total_white - total_black);

        if(bb == 0 && ww == 0) { //otherwise, there is no impossible coloring
            long long int forbidden = fastPow(2, uu); //Initialize with colorings with WB or BW only, then substract colorings with WB only and BW only
            if(wb+wu+ub > 0) forbidden--;
            if(bw+bu+uw > 0) forbidden--;
            ret-= forbidden;
        }
        cout << ret%998244353 << endl;

    }
    return 0;
}