/*
    Problem : https://codeforces.com/contest/2020/problem/B
    Author : Baptiste Prévost
    Subjects : binary search, divisors, perfect squares

    Idea : The only bulbs are the perfect squares, because all others have an even number of divisors

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
 
    ull k;
    while(t--) {
        cin >> k;
        
        ull l=k, r=4*k;
 
        while(r-l>1) {
 
            ull m = (r+l) >> 1;
            ull perfectSquares = sqrtl(m);
            
            if(m-perfectSquares >= k) r=m;
            else l=m;
        }
        cout << r << endl;
    }
    cout << (ull)sqrt(854258780613619263) << endl;
    return 0;
}