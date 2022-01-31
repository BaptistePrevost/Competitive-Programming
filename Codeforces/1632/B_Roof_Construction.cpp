/*
    Author : Baptiste Prévost

    Idea :
        -
        -
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

ll pow2[21];
void first() {
    pow2[0]=1;
    frr(i,1,21) {
        pow2[i]=2*pow2[i-1];
    }
}

ll find(ll n) {
    int i=0;
    while(pow2[i]<=n) {
        i++;
    }
    return i-1;
}

int main() {
    ll t, n;
    cin >> t;
    first();
    while(t--) {
        cin >> n;
        ll exp = find(n-1);
        for(ll i=n-1; i>=pow(2,exp); i--) cout << i << " ";
        cout << 0 << " ";
        for(ll i=pow(2,exp)-1; i > 0; i--) cout << i << " ";

        cout << endl;
    }

    return 0;
}
