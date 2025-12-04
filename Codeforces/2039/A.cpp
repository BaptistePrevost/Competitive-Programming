/*
    Problem : 
    Author : Baptiste Prévost
    Subjects :

    Idea :

    Complexity :
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fastIO();
    int t;
    cin >> t;

    ll n;
    while(t--) {
        cin >> n;
        vector<ll> ans = {2};
        ll x = 3;
        forn(i,1,n-1) {
            ans.push_back(x);
            x+=2;
        }
        forn(i,0,n-1) cout << ans[i] << " ";
        
        cout << endl;
    }

    return 0;
}
