/*
    Author : Baptiste Prévost

    Idea :
        - Just find the initial expression in terms of n, then binary exponentiation works
*/

#include<bits/stdc++.h>
using namespace std;

#define forn(i, n)  for (int i = 0; i < int(n); i++)
typedef long long int ll;
const ll M=10000007;

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
        if(b&1) res=(res*a)%M;
        a=(a*a%M);
        b>>=1;
    }
    return res%M;
}

int main() {
    ll n, k, ans;
    while(1) {
    cin >> n >> k;
    if(n==0 && k==0) break;
    
    ans=0;
    ans+=fastPow(n,k)+2*fastPow(n-1, k) + 2*fastPow(n-1, n-1) + fastPow(n,n);
    cout << ans%M << endl;
    }

    return 0;
}
