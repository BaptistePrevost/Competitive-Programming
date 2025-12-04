/*
    Problem : https://codeforces.com/contests/2044/problems/B
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
        for(auto it = s.rbegin(); it<s.rend(); it++) {
            if(*it == 'p') cout << 'q';
            if(*it == 'q') cout << 'p';
            if(*it == 'w') cout << 'w';
        }
        
        cout << endl;
    }

    return 0;
}
