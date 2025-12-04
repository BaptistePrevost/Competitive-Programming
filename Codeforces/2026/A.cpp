/*
    Problem : 
    Author : Baptiste Prévost
    Subjects :

    Idea :

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

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll x, y, k;
        cin >> x >> y >> k;
        x = min(x,y);
        cout << "0 0 " << x << " " << x << endl;
        cout << "0 " << x << " " << x << " 0" << endl;
    }

    return 0;
}
