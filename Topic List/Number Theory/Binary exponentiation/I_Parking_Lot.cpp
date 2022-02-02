/*
    Author : Baptiste Prévost

    Idea :
        - Exercice de fastPow
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

ll fastPow(ll a, ll b) {
    ll res=1;
    while(b) {
        if(b&1) res*=a;
        a=a*a;
        b>>=1;
    }
    return res;
}

int main() {
    ll n;
    cin >> n;

    ll temp = fastPow(4,n-3);
    cout << (n-3)*9*temp + 24*temp;
    return 0;
}