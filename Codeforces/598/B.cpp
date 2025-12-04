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
    string s;
    cin >> s;

    ll m;
    cin >> m;
    ll l, r, k;
    forn(i,1,m) {
        cin >> l >> r >> k;
        r--; l--;
        ll d = r-l+1;
        string temp = s.substr(l, d);
        k %= d;
        k = d-k;
        forn(j, l, r) s[j] = temp[(k + j - l) % d];
    }

    cout << s << endl;
    return 0;
}
