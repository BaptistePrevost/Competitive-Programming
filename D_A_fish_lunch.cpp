/*
    Author : Baptiste Prévost

    Unfinished
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

int main() {
    double N, N1, N2, I, P;
    cin >> N >> N1 >> N2 >> I >> P;
    if(I<=N2) cout << 1;
    else cout << N2*(1-pow(1 - P/100, I-1))/N;
    return 0;
}