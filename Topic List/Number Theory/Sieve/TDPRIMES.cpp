#include<bits/stdc++.h>
using namespace std;

vector<bool> sieve(int n) {
    /*
        Ignore the even numbers
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

int main() {
    int n = 1e8;
    vector<bool> is_prime = sieve(n);
    int count=1;
    cout << 2 << endl;
    for(int i=3; i<n; i+=2) {
        if(is_prime[i]) {
            count++;
            if(count%100==1) cout << i << endl;
        }
    }
    return 0;
}