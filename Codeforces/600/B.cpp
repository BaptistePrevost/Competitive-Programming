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
    vector<ll> a(n);
    forn(i,0,n-1) cin >> a[i];
    sort(a.begin(), a.end());

    ll b;
    forn(i,1,m) {
        cin >> b;
        ll l=-1, r=n;
        while(r-l>1) {
           ll mid = (r+l)>>1;
           if(a[mid] <= b) l = mid;
           else r = mid;  
        }
        cout << l+1 << " ";
    }
    cout << endl;
    return 0;
}
