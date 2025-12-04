#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vll;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define out(x) cout << x << " ";
#define outln(x) cout << x << endl;

// Returns a value in [a,b]
ll rnd(ll a, ll b){
    return a + rand() % (b - a + 1);
}

int main() {
    std::srand(chrono::steady_clock::now().time_since_epoch().count());
    const ll N = 100;
    const ll K = 10000;

    ll n = rnd(1,N);
    ll k = rnd(1,K);
    ll x = rnd(1, n+k);
    out(n) out(k) outln(x)
    forn(i,1,n) {
        out(rnd(1,N))
    }
    outln(' ')
    return 0;
}