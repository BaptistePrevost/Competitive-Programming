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

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fastIO();
    int t;
    cin >> t;

    string s;
    while(t--) {
        cin >> s;

        bool found = false;
        for(int i=0; i<(int)s.size() - 1; i++) {
            if(s[i] == s[i+1]) {
                cout << s[i] << s[i+1] ;
                found = true;
                break;
            }
            if(i+2 < s.size() && s[i+2] != s[i] && s[i+2] != s[i+1]) {
                cout << s[i] << s[i+1] << s[i+2];
                found = true;
                break;  
            }
        }
        if(!found) cout << -1;
        cout << endl;
    }

    return 0;
}
