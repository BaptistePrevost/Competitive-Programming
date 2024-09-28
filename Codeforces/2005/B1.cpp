/*
    Problem : https://codeforces.com/contest/2005/B
    Author : Baptiste Prévost
    Subjects :

    Idea : Straightforward case disjunction

    Complexity : 1
*/

#include <bits/stdc++.h>
#include <vector>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    ll t;
    cin >> t;

    ll n, m, q;
    ll b[2];
    ll a;
    while(t--) {
        cin >> n >> m >> q;
        for(ll i=0; i<m; i++) {
            cin >> b[i];
        }
        if(b[0] > b[1]) swap(b[0], b[1]);
        cin >> a;

        ll ans = 0;
        if(a < b[0]) {
            ans = b[0]-1;
        } else if(a > b[1]) {
            ans = n-b[1];
        } else {
            ans = (b[1]-b[0])/2;
        }
        cout << ans << endl;
    }
}
