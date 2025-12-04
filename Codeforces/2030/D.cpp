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

    while(t--) {
        ll n, q;
        cin >> n >> q;
        string s;
        vector<ll> a(n);
        forn(i,0,n-1) cin >> a[i];
        cin >> s;

        vector<ll> pref(n);
        pref[0] = a[0]-1;
        forn(i,1,n-1) pref[i] = max(pref[i-1], a[i]-1);


        auto block = [&](ll i){return (s[i] == 'L' && s[i+1] == 'R');};

        ll nbConflicts = 0;
        forn(i,0,n-2) {
            if(block(i) && pref[i] > i) nbConflicts++;
        }

        ll pos;
        forn(i,1,q) {
            cin >> pos;
            pos--;
            if(s[pos] == 'L') {
                if(block(pos) && pref[pos] > pos) nbConflicts--;
                s[pos] = 'R';
                if(block(pos-1) && pref[pos-1] > pos) nbConflicts++;
            } else {
                if(block(pos-1) && pref[pos-1] > pos-1) nbConflicts--;
                s[pos] = 'L';
                if(block(pos) && pref[pos] > pos) nbConflicts--;
            }
            cout << (nbConflicts == 0 ? "YES" : "NO") << endl;
        }

    }

    return 0;
}
