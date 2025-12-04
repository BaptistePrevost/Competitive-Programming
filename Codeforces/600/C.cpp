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
    string s;
    cin >> s;

    vector<int> freq(26, 0);
    forn(i,0,s.size()-1) {
        freq[s[i]-'a']++;
    }
    vector<int> odds;
    forn(i,0,25) {
        if(freq[i]%2 == 1) odds.push_back(i);
    }

    int l=0, r=odds.size()-1;
    while(l < r) {
        freq[odds[l]]++;
        freq[odds[r]]--;
        l++; r--;
    }
    
    forn(i,0,25) {
        forn(j,1,freq[i]>>1) cout << (char)('a'+i);
    }
    if(l == r) cout << (char)('a'+odds[l]);
    rofn(i,25,0) {
        forn(j,1,freq[i]>>1) cout << (char)('a'+i);
    }
    

    return 0;
}
