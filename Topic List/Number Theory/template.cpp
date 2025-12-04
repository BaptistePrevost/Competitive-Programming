#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;

/*
    A benchmark (https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html#:~:text=A%20benchmark%20(link)%20shows%2C%20that%20using%20a%20vector%3Cbool%3E%20is%20between%201.4x%20and%201.7x%20faster%20than%20using%20a%20vector%3Cchar%3E.) 
    shows, that using a vector<bool> is between 1.4x and 1.7x faster than using a vector<char> for "normal" sieve.
    For segmented sieve, vector<char> is >2x faster.
*/
#define MAX_N 10000000

vll sieve_list(ll N) {
    vector<bool> is_prime(MAX_N+1, true);
    vll primes;
    is_prime[0] = is_prime[1] = false;
 
    for (ll i = 2; i * i <= N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (ll i = 2; i <= N; ++i) {
        if (is_prime[i]) primes.push_back(i);
    }
 
    return primes;
}

vector<char> segmented_sieve_list(ll L, ll R) {
    vll small_primes;
    ll Rsqrt = sqrt(R);
    vector<char> small_is_prime(Rsqrt+2, true);
    for (ll i=2; i<=Rsqrt; i++) {
        if(small_is_prime[i]) {
            small_primes.push_back(i);
            for (ll j=i*i; j<=Rsqrt; j+=i) {
                small_is_prime[j] = false;
            }
        }
    }
    
    vector<char> is_prime(R-L+1, true);
    for(ll p : small_primes)
        for(ll j=max(p*p, (L-p+1)/(p*p)); j<=R; j+=p)
            is_prime[j-L]=false;

    if(L==1) is_prime[0]=false;
    return is_prime;
}