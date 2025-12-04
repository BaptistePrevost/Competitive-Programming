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
#define yon(t) cout << (t ? "YES" : "NO") << endl;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fastIO();
    ll n, m;
    cin >> n >> m;
    vector<ll> p(n+1);
    forn(i,1,n) cin >> p[i];

    sort(p.begin(), p.end());

    ll ans = 0;
    forn(i,1,n) {
        ll left=-1, right=sqrt(m/p[i])+1;
        while(right-left>1) {
            ll mid = (right+left)/2;
            if(mid*mid*p[i] > m) right=mid;
            else left=mid;
        }
        ans += left;
        m -= left*left*p[i];
        if(m==0) break;
    }

    cout << ans << endl;

    return 0;
}
