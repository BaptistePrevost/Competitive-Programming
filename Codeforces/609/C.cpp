/*
    Problem : 
    Author : Baptiste Prévost
    Subjects :

    Idea :

    Complexity :
*/

#include <bits/stdc++.h>
#include <vector>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)

int main() {
    ll n;
    cin >> n;
    vector<ll> m(n);
    ll s = 0;
    forn(i,0,n-1) {
        cin >> m[i];
        s += m[i];
    }

    ll topGoal = s/n, botGoal = s/n;
    if(s%n) topGoal++;
    ll topAns = 0, botAns = 0;
    for(auto v : m) {
        topAns += max((ll)0, v-topGoal);
        botAns += max((ll)0, botGoal-v);
    }
    
    cout << max(topAns, botAns) << endl;
    return 0;
}
