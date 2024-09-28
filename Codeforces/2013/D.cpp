/*
    Problem : https://codeforces.com/contest/2013/problems/D
    Author : Baptiste Prévost
    Subjects : Binary search, minimax

    Idea : With binary search, we will look for alpha = the smallest maximum possible in a
    and beta = the largest minimum possible.
    
    When testing a value alpha for the maximum, we can go through values from left to right. If the element
    is above alpha, then we can empty it on the next element. If the last value is valid, alpha is a possible
    maximum.
    This algorithm can only increase the minimum of the array.

    Going through values in reverse order allows to look for the validity of a candidate for beta.
    This algorithm only decreases the maximum of the array.

    Therefore, we can first search alpha the smallest possible maximum while maintaining. Then looking for beta,
    the maximum cannot become any larger, and will not become any smaller.

    The answer will then be alpha - beta

    Complexity : nlogn
*/

#include <bits/stdc++.h>
#include <vector>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)

int main() {
    ll t;
    cin >> t;

    ll n;
    while(t--) {
        cin >> n;
        vector<ll> a(n);
        ll mn = 1e15, mx=-1;
        forn(i, 0, n-1) {
            cin >> a[i];
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }
        
        ll low = -1, high = mx;
        ll alpha, beta;
        while(low+1 < high) {
            alpha = (low + high) / 2;
            vector<ll> b(n);
            forn(i, 0, n-1) {
                b[i] = a[i];
            }
            forn(i, 0, n-2) {
                if(b[i] > alpha) {
                    b[i+1] += b[i] - alpha;
                    b[i] = alpha;
                }
            }
            if(b[n-1] > alpha) low = alpha;
            else high = alpha;
        }
        alpha = high;

        low = mn; high = 1e15;
        while(low+1 < high) {
            beta = (low + high) / 2;
            vector<ll> b(n);
            forn(i, 0, n-1) {
                b[i] = a[i];
            }
            rofn(i, n-1, 1) {
                if(b[i] < beta) {
                    b[i-1] -= beta - b[i];
                    b[i] = beta;
                }
            }
            if(b[0] < beta) high = beta;
            else low = beta;
        }
        beta = low;

        cout << alpha - beta << endl;

    }
}
