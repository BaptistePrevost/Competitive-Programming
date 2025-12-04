/*
    Problem : 
    Author : Baptiste Prévost
    Subjects :

    Idea :

    Complexity :
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)

int main() {
    int a, b;
    unordered_map<int, int> l;
    unordered_map<int, int> r;
    
    while(scanf("%i %i", &a, &b) == 2) {
        l[a] = l[a] + 1;
        r[b] = r[b]+ 1;
    }
    

    int ans=0;
    for(auto kv : l) {
        ans += kv.first*r[kv.first]*kv.second;
    }

    cout << ans << endl;

    return 0;
}
