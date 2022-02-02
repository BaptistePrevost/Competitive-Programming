/*
    Author : Baptiste Prévost

    Idea :
        - Trivial using fastPow modified with %10
*/

#include<bits/stdc++.h>
using namespace std;

#define forn(i, n)  for (int i = 0; i < int(n); i++)
typedef long long int ll;
const ll M=1e9+7;

#define sz(x)       ((ll) (x).size())
#define all(x)      (x).begin(), (x).end()
#define pll         pair<ll,ll>
#define vl          vector<ll>
#define ff          first
#define ss          second
#define pb          push_back
#define pp          pop_back
#define frr(i,j,k)  for(ll i=j; i<k; i++)
#define andar(x)    for(ll&i:x) cin>>i;
#define bahar(x)    for(ll&i:x) cout<<i<<' ';

long long fastPow(long long a, long long b) {
    long long res=1;
    while(b) {
        if(b&1) res = (res*a)%10;
        a=(a*a)%10;
        b>>=1;
    }
    return res%10;
}

int main() {
    ll t, a, b;
    cin >> t;

    while(t--) {
        cin >> a >> b;
        cout << fastPow(a, b) << endl;
    }

    return 0;
}
