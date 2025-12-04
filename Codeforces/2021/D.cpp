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
    int t;
    cin >> t;

    ll n, m;
    while(t--) {
        cin >> n >> m;
        
        vector<ll> a(m+1);

        vector<ll> prefixSum(m+1);
        vector<ll> prefixMax(m+1);

        vector<ll> suffixMax(m+1);

        vector<ll> combinedPrefixMax(m+1);
        vector<ll> combinedSuffixMax(m+1);

        vector<ll> dpL(m+1), dpR(m+1);
        vector<ll> dqL(m+1, 0), dqR(m+1, 0);

        // i==1
        forn(j,1,m) cin >> a[j];
        forn(p,0,m) {
            prefixSum[p] = p > 0 ? prefixSum[p-1] + a[p] : 0;
            prefixMax[p] = p > 0 ? max(prefixMax[p-1], -prefixSum[p]) : 0; 
        }
        rofn(p,m,0) {
            suffixMax[p] = p < m ? max(suffixMax[p+1], prefixSum[p]) : prefixSum[m];
        }
        forn(r,0,m) {
            dpR[r] = r > 0 ? prefixSum[r] + prefixMax[r-1] : -1e18;
        }
        rofn(l,m,0) {
            dpL[l] = l < m ? -prefixSum[l] + suffixMax[l+1] : -1e18;
        }

        forn(i,2,n) {
            swap(dpL, dqL);
            swap(dpR, dqR);
            forn(j,1,m) cin >> a[j];
            forn(p,0,m) {
                prefixSum[p] = p > 0 ? prefixSum[p-1] + a[p] : 0;
                prefixMax[p] = p > 0 ? max(prefixMax[p-1], -prefixSum[p]) : 0; 
            }
            rofn(p,m,0) {
                suffixMax[p] = p < m ? max(suffixMax[p+1], prefixSum[p]) : prefixSum[m];
            }
            combinedPrefixMax[0] = -1e18;
            forn(p,1,m) {
                combinedPrefixMax[p] = max(combinedPrefixMax[p-1], prefixMax[p-1] + max(dqR[p], dqL[p]));
            }
            combinedSuffixMax[m] = -1e18;
            rofn(p,m-1,0) {
                combinedSuffixMax[p] = max(combinedSuffixMax[p+1], suffixMax[p+1] + max(dqR[p], dqL[p]));
            }
            dpR[0] = dpR[1] = -1e18;
            forn(r,2,m) {
                dpR[r] = prefixSum[r] + combinedPrefixMax[r-1];
            }
            dpL[m] = dpL[m-1] = -1e18;
            rofn(l,m-2,0) {
                dpL[l] = -prefixSum[l] + combinedSuffixMax[l+1];
            }
        }

        ll ans = -1e18;
        forn(p,0,m) {
            ans = max(ans, dpL[p]);
            ans = max(ans, dpR[p]);
        }
        cout << ans << endl;
    }

    return 0;
}
