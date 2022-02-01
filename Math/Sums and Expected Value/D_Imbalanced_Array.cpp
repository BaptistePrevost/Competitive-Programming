/*
    Author : Baptiste Prévost

    Idea :
        - Iterate over the values, and count the number segments where it is respectively the mostleft minimum, and mostleft maximum.
        - Using mostleft (-right) avoid counting some segments twice
        - I computed left and right first greedily, algorithm was in O(n**2). I used tutorial https://codeforces.com/blog/entry/52638 that taught me to use a stack, making the complexity O(n)
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
#define ifrr(i,j,k)  for(ll i=j; i>=k; i--)
#define andar(x)    for(ll&i:x) cin>>i;
#define bahar(x)    for(ll&i:x) cout<<i<<' ';

int main() {
    ll n, a;
    cin >> n;
    // cout << "n " << n << endl;
    vl arr;
    frr(i, 0, n) {
        cin >> a;
        arr.push_back(a);
    }

    ll ans=0;
    
    vl stack, left(n), right(n);
    
    frr(i,0,n) {
        while(!stack.empty() && arr[stack.back()]<=arr[i]) stack.pop_back();
        if(stack.empty()) left[i]=-1;
        else left[i]=stack.back();
        stack.push_back(i); 
    }

    stack.clear();
    ifrr(i,n-1,0) {
        while(!stack.empty() && arr[stack.back()]<arr[i]) stack.pop_back();
        if(stack.empty()) right[i]=n;
        else right[i]=stack.back();
        stack.push_back(i); 
    }

    frr(i, 0, n) ans+=arr[i]*(i-left[i])*(right[i]-i);

    stack.clear();
    frr(i,0,n) {
        while(!stack.empty() && arr[stack.back()]>=arr[i]) stack.pop_back();
        if(stack.empty()) left[i]=-1;
        else left[i]=stack.back();
        stack.push_back(i); 
    }

    stack.clear();
    ifrr(i,n-1,0) {
        while(!stack.empty() && arr[stack.back()]>arr[i]) stack.pop_back();
        if(stack.empty()) right[i]=n;
        else right[i]=stack.back();
        stack.push_back(i); 
    }

    frr(i, 0, n) ans-=arr[i]*(i-left[i])*(right[i]-i);

    cout << ans;
    return 0;
}
