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
    ll t, n;
    string s, ans;
    cin >> t;

    while(t--) {
        cin >> n;
        cin >> s;
        if(n==1) ans="YES";
        else if (n==2) {
            if(s[0]!=s[1]) ans="YES";
            else ans="NO";
        } else ans="NO";

        cout << ans << endl;


    }

    return 0;
}
