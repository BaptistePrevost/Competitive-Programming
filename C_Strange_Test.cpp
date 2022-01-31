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

int main() {
    ll t;
    ll a, b;
    cin >> t;

    while(t--) {
        ll pow2[20];
        for(int i=0; i<20; i++) {
            pow2[i]=1<<i;
        }
        cin >> a >> b;
        ll ans=M;
        frr(a2, a, b+1) {
            ll weight=0;
            while((b>>weight)!=1) weight++;
            ll b2=0;
            for(ll w=weight; w>=0; w--) {
                if(((b>>w)&1)==1) b2|=1<<w;
                else if(((a2>>w)&1)==1) {
                    b2|=1<<w;
                    break;
                }
            }
            ans=min(ans, a2 + (a2|b2));
        }
        ans += (1-a-b);
        ans = min(ans, b-a);
        cout << ans << endl;
    }

    return 0;
}
