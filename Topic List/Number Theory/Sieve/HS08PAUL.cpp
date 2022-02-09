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

const int N=10000000;
vector<bool> is_prime = sieve(N);
map<int, bool> seen;
list<int> candidates;

int main() {
    int t, n, ans, current;

    candidates.push_back(2);
    for(int x=1; x*x<=N; x++) {
        for(int y=1; y*y*y*y + x*x <= N; y++) {
            current = x*x + y*y*y*y;
            if( (current&1) && is_prime[current] && !seen[current]) {
                seen[current]=true;
                candidates.push_back(current);
            }
        }
    }

    candidates.sort();

    cin >> t;

    while(t--) {
        cin >> n;
        ans=0;
        for(auto candidate : candidates) {
            if(candidate>n) break;
            ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
