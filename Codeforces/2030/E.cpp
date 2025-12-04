/*
    Problem : https://codeforces.com/contest/2030/problem/E
    Author : Baptiste Prévost
    Subjects : dynamic programming, combinatorials, contribution technique

    Idea : This is a combinatorial question.
    **Observation** : For any subsequence b,
    score(b) = freq[0] + min(freq[0], freq[1]) + min(freq[0], freq[1], ...) ...
    The proof is :
        - each 0 can contribute to the score by being placed in a new subset,
        - each 1 can be contribute to the score if it can be placed with a zero,
        - etc

    We now need to compute for each value i from 0 to n-1 their contribution, i.e for each
    occurence j from 1 to freq[i] the number of subsequence in which it will actively
    contribute to increase the score.

    dp[i][j] denotes the number of subsequences with values [0,...,i]
    s.t all values are present at least j times, and there is at least one value 
    present exactly j times.
    dp[i][j] = 
        dp[i-1][j]*sum_{k=j}^{k=n}(among(k, freq[i])) //minimum j is reached before i
        + among(j, freq[i])*sum_{k=j+1}^{k=n}(dp[i-1][k]) //i reaches minimum j


    Complexity : 
    Prefix/Suffix sums can reduce complexity
    Then, since j is lower or equal to min(freq[0], ..., freq[i]), the sum of all loops
    over j won't exceed n iterations.
    O(n)
*/

#include <bits/stdc++.h>
#include <vector>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)

struct Combinatorial {
    vector<ll> fact, ifact, twoPows;
    ll n = 2*1e5+5;
    ll MOD = 998244353;

    ll binaryExponentiation(ll base, ll exp) {
        ll ans = 1;
        while(exp > 0) {
            if(exp & 1) {
                ans = (ans*base) % MOD;
            }
            base = (base*base) % MOD;
            exp >>= 1;
        }
        return ans;
    }

    ll among(ll k, ll n) {
        if(k<0 || k>n) return 0;
        return (fact[n]*((ifact[k]*ifact[n-k])%MOD))%MOD;
    }
    
    ll twoPow(ll exp) {
        return twoPows[exp];
    }

    Combinatorial(ll n, ll MOD) : n(n), MOD(MOD) {
        fact.resize(n+1);
        ifact.resize(n+1);
        twoPows.resize(n+1);

        fact[0] = 1;
        forn(i,1,n) fact[i] = (fact[i-1]*i)%MOD;
        ifact[n] = binaryExponentiation(fact[n], MOD-2);
        rofn(i,n-1,0) ifact[i] = (ifact[i+1]*(i+1))%MOD;
        twoPows[0] = 1;
        forn(i,1,n) twoPows[i] = (twoPows[i-1]*2)%MOD;
    }

};

int main() {
    int t;
    cin >> t;
    ll n;

    const ll N = 2*1e5+5;
    const ll MOD = 998244353;
    Combinatorial combo(N, MOD);
    
    while(t--) {
        cin >> n;
        vector<ll> a(n);
        vector<ll> cnt(n, 0);
        ll moreOrEqualToN = 0;
        forn(i,0,n-1) {
            cin >> a[i];
            if(a[i] < n) cnt[a[i]]++;
            else moreOrEqualToN++;
        }

        vector<ll> above(n);
        above[n-1] = moreOrEqualToN;
        rofn(i,n-2,0) above[i] = (above[i+1]+cnt[i+1]) % MOD;

        vector<ll> dpSub(n+5);
        vector<ll> dpSubSuffix(n+5);
        vector<ll> amongSuffix(n+5);
        // dpSub[i][j] is the number of subsequences in a with values in {0,1,...,i} st 
        // each value is present at least j times, and at least on value is at most j times
        ll ans = 0;
        forn(i,1,cnt[0]) {
            dpSub[i] = combo.among(i, cnt[0]);
            ans = (ans + ((((dpSub[i]*i)%MOD)*combo.twoPow(above[0]))%MOD)) % MOD;
        }
        ll dpSize = cnt[0];
        forn(i,1,n-1) {
            dpSubSuffix[dpSize+1] = 0;
            rofn(j, dpSize, 1) {
                dpSubSuffix[j] = (dpSubSuffix[j+1] + dpSub[j]) % MOD;
            }
            dpSize = min(dpSize, cnt[i]);
            dpSub[dpSize+1] = 0;
            if(dpSize == 0) break;
            amongSuffix[cnt[i]+1] = 0;
            rofn(j, cnt[i], 0) amongSuffix[j] = (amongSuffix[j+1] + combo.among(j, cnt[i])) % MOD;
            rofn(j, dpSize, 1) {
                dpSub[j] = (
                    (dpSub[j]*amongSuffix[j]) % MOD
                    + (combo.among(j, cnt[i])*dpSubSuffix[j+1]) % MOD) % MOD;
                ans = (ans + ((((dpSub[j]*j)%MOD)*combo.twoPow(above[i]))%MOD)) % MOD;
            }
        }
        
        cout << ans << endl;
    }

    return 0;
}
