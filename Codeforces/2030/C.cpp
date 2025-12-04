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
    int t;
    cin >> t;

    ll n;
    while(t--) {
        cin >> n;
        string s;
        cin >> s;

        bool ans = false;
        if(s[0] == '1' || s.back() == '1') ans = true;
        forn(i,1,n-1) if(s[i] == '1' && s[i+1] == '1') ans = true;

        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}
