/*
    Author : Baptiste Prévost

    Idea :
        -
        -
*/

#include<bits/stdc++.h>
using namespace std;

const int N=10000025;

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
            int mod=10;
            bool test=true;
        }
    }
    return is_prime;
}

vector<bool> is_prime;

bool afraid(int n) {
    int mod = 10;
    while(mod<n) {
        if(n%mod<mod/10) return false;
        if(!is_prime[n%mod]) return false;
        mod*=10;
    }
    return true;
}



int main() {
    int t, n, ans;
    cin >> t;

    is_prime = sieve(N);
    vector<int> count(N, 0);
    count[2]=1;
    for(int i=3; i<N; i++) {
        count[i] = count[i-1];
        if((i&1) && is_prime[i] && afraid(i)) count[i]+=1;
    }

    while(t--) {
        cin >> n;
        cout << count[n] << endl;
    }

    return 0;
}
