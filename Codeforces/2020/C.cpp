/*
    Problem : https://codeforces.com/contest/2020/problem/C
    Author : Baptiste Prévost
    Subjects : bitmask, carry

    Idea : Simple truth table

    Complexity :
*/

#include <bits/stdc++.h>
#include <vector>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)
#define debug(x) cout << x << endl;

int main() {
    int t;
    cin >> t;

    ull a, b, c, d;
    while(t--) {
        cin >> b >> c >> d;
        a = 0;
        int pos = 0;
        ull mask = 1;
        while(pos < 62) {
            ull bb = (b&mask);
            ull cb = (c&mask);
            ull db = (d&mask);
            if((bb==0 && cb==0 && db==mask) || (bb==mask && cb==mask && db==0)) {
                a |= mask;
            } else if (bb != cb && cb == db) {
                pos = -1;
                break;
            }
            mask <<= 1;
            pos++;
        }
        if(pos == -1) cout << -1 << endl;
        else cout << a << endl;
    }

    return 0;
}
