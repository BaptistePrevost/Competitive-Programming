/*
    Problem : https://codeforces.com/contest/1366/problem/D
    Author : Baptiste Prévost
    Subjects : primes, optimal solution characteristics, number theory

    Idea : One can show that we need d1^d2=1. Then for each prime p | a, we need p !| (d1+d2) => p !| d1 or p !| d2.
    Taking a prime factor of a for d1, and p !| d1 will almost always be true.
    We need to build d2 st d2 | a and d1 !| d2. Divide a by d1 as much as possible to get d2. If d2 > 1, then we found a valid pair.

    Complexity : sieve
*/

#include <bits/stdc++.h>
#include <vector>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)

const ll N = 1e7+9;

int main() {
    ll n;
    cin >> n;

    vector<ll> minDiv(N+1, 0);
    minDiv[1] = 1;
    forn(i,2,N) {
        if(minDiv[i] == 0) {
            minDiv[i] = i;
            forn(j,2,N) {
                if(j*i>N) break;
                if(minDiv[j*i] == 0) minDiv[j*i] = i;
            }
        }
    }


    ll a;
    vector<ll> v(n), w(n);
    forn(i,0,n-1) {
        cin >> a;
        ll p = minDiv[a];
        while(a%p==0) a/=p;
        if(a>1) {
            v[i] = p; w[i] = a;
        } else {
            v[i] = -1; w[i] = -1;
        }
    }

    forn(i,0,n-1) cout << v[i] << " ";
    cout << endl;
    forn(i,0,n-1) cout << w[i] << " ";
    cout << endl;

    return 0;
}
