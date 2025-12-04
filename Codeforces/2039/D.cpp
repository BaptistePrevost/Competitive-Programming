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

    ull m, n;
    while(t--) {
        cin >> m  >> n;
        vector<bool> s(n+1);
        ll mx;
        vector<ll> a(n+1);
        bool valid = true;

        forn(i,1,m) {
            cin >> mx;
            s[mx] = true; 
        }
        a[1] = mx;
        for(ll x=a[1]; x<=n; x+=a[1]) s[x] = false;

        forn(i,2,n) {
            while(mx > 0 && s[mx] == false) mx--;
            if(mx == 0) {
                valid = false;
                break;
            }
            
        }

        if(valid) {
            forn(i,1,n) cout << a[i] << ' ';
        } else {
            cout << "-1";
        }
        cout << endl;
    }

    return 0;
}
