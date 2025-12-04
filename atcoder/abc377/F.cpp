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
    ll n, m;
    cin >> n >> m;
    ll ans = n*n;

    ll i, j;
    vector<bool> row(n+1, true);
    vector<bool> col(n+1, true);
    vector<bool> asc(2*n, true);
    vector<bool> des(2*n, true);
    forn(k,1,m) {
        cin >> i >> j;
        row[i] = false;
        col[j] = false;
        

    }

    for(auto p : s) {
        ans -= p.second.size();
    }


    cout << ans << endl;

    return 0;
}
