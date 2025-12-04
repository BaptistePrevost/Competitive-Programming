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
    vector<string> b(8);
    forn(i,0,7) cin >> b[i];
    
    vector<bool> r(8, true);
    vector<bool> c(8, true);

    forn(i,0,7) {
        forn(j,0,7) {
            if(b[i][j] == '#') {
                r[i] = false;
                c[j] = false;
            }
        }
    }

    int ans = 0;
    forn(i,0,7) {
        if(!r[i]) continue;
        forn(j,0,7) {
            if(!c[j]) continue;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
