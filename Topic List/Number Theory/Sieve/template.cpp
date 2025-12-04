/*
    A benchmark (https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html#:~:text=A%20benchmark%20(link)%20shows%2C%20that%20using%20a%20vector%3Cbool%3E%20is%20between%201.4x%20and%201.7x%20faster%20than%20using%20a%20vector%3Cchar%3E.) 
    shows, that using a vector<bool> is between 1.4x and 1.7x faster than using a vector<char> for "normal" sieve.
    For segmented sieve, vector<char> is >2x faster.
*/

#include<bits/stdc++.h>
using namespace std;

vector<bool> sieve_vector(int n) {
    /*
        Ignore the even numbers.
        Return a vector of boolean
    */
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i=3; i*i <= n; i+=2) {
        if(is_prime[i]) {
            for(int j=i*i; j<=n; j+=2*i) {
                is_prime[j]=false;
            }
        }
    }
    return is_prime;
}

vector<int> sieve_list(int n) {
    /*
        Ignore the even numbers
        Return a vector of prime int
    */
    vector<bool> is_prime(n+1, true);
    vector<int> primes = {2};
    is_prime[0] = is_prime[1] = false;
    for(int i=3; i*i <= n; i+=2) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j=i*i; j<=n; j+=2*i) {
                is_prime[j]=false;
            }
        }
    }
    return primes;
}

unsigned int countPrimes(unsigned int n) {
    /*
        Use the 'sieving till root' optimisation for time complexity.
        Split the complete range in block of size S for memory complexity.
    */
    const int S = 10000;
    vector<int> primes;
    int nsqrt = sqrt(n);
    vector<char> is_prime(nsqrt+2, true);
    int i=2;
    is_prime[0]=is_prime[1]=false;
    for(int i=2; i<=nsqrt; i++) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j = i*i; j<=nsqrt; j+=i) {
                is_prime[j]=false;
            }
        }
        i++;
    }

    unsigned int result = 0;
    vector<char> block(S);
    for(unsigned int k=0; k*S <= n; k++) {
        fill(block.begin(), block.end(), true);
        unsigned int start = k*S;
        for(unsigned int p: primes) {
            unsigned int start_idx = (start + p - 1) / p;
            int j = max(start_idx, p)*p - start;
            for(; j < S; j += p) {
                block[j] = false;
            }
        }
        if(k==0) block[0] = block[1] = false;
        for (unsigned int i = 0; i<S && start + i <= n; i++) {
            if(block[i]) result++;
        }
    }
    return result;
}

vector<char> segmentedSieve(long long unsigned L, long long unsigned R) {
    /*
        Could still be optimised by ignoring the even numbers
    */
    long long unsigned lim = sqrt(R);
    vector<char> mark(lim+1, false);
    vector<long long unsigned> primes;

    for(long long unsigned i=2; i<=lim; ++i) {
        if(!mark[i]) {
            primes.emplace_back(i);
            for(long long unsigned j=i*i; j<=lim; j += i) mark[j]=true;
        }
    }
    
    vector<char> isPrime(R - L + 1, true);
    for (long long unsigned i : primes)
        for (long long unsigned j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}


int main() {
    return 0;
}