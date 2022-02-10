/*
    Author : Baptiste Prévost

    Idea :
        -
        -
*/

#include<bits/stdc++.h>
using namespace std;

list<int> sieve(int n) {
    /*
        Ignore the even numbers
    */
    vector<bool> is_prime(n+1, true);
    list<int> primes = {2};
    is_prime[0] = is_prime[1] = false;
    for(int i=3; i <= n; i+=2) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j=i*i; j<=n; j+=2*i) {
                is_prime[j]=false;
            }
        }
    }
    return primes;
}

int dfp(int n, list<int> primes) {
    list<int>::iterator it = primes.begin();
    int ans=0;
    while(n!=1 && it != primes.end()) {
        if(!(n%(*it))) {
            while(!(n%(*it))) n/=(*it);
            ans++;
        }
        it++;
    }
    return ans;
}

int main() {
    int n, ans=0;
    cin >> n;
    list<int> primes = sieve(n);
    for(int i=2; i<=n; i++) {
        // cout << dfp(i, primes) << endl;
        if(dfp(i, primes)==2) ans++;
    }
    cout << ans << endl;
    return 0;
}
