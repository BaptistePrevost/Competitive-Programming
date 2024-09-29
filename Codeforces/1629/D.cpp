/*
    Problem : https://codeforces.com/contest/1629/problem/D
    Author : Baptiste Prévost
    Subjects : string, palindrom, optimal solution characteristics

    Idea : Since all strings are length 2 or 3, any palindrom subsequence can be reduced to be only 1 ou 2 strings long.
    Process each string by checking whether suitable palindrom candidates have been seen earlier.
    Using arrays here.

    Complexity : n
*/

#include <bits/stdc++.h>
#include <vector>
#include <unordered_set>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)

template<typename T>
bool isIn(unordered_set<T> s, T v) {
    return (s.find(v) != s.end());
}

int main() {
    int t;
    cin >> t;

    ll n;
    while(t--) {
        cin >> n;
        string s, r;
        // Indexed by s[0], s[1], s[2]. index 26 used for size 2
        vector<vector<vector<bool>>> completeSeen(26, vector<vector<bool>>(26, vector<bool>(27, false)));
        vector<vector<bool>> truncatedSeen(26, vector<bool>(26, false));

        bool ans = false;
        forn(i, 0, n-1) {
            cin >> s;
            if(!ans) {
                if(s.size() == 1) {
                    ans = true;
                } else if(s[0] == s[s.size()-1]) {
                    ans = true;
                } else {
                    if(s.size() == 2) {
                        if(completeSeen[s[1]-'a'][s[0]-'a'][26]) ans = true;
                        if(truncatedSeen[s[1]-'a'][s[0]-'a']) ans = true;

                        completeSeen[s[0]-'a'][s[1]-'a'][26] = true;
                    } else {
                        if(completeSeen[s[2]-'a'][s[1]-'a'][s[0]-'a']) ans = true;
                        if(completeSeen[s[2]-'a'][s[1]-'a'][26]) ans = true;

                        completeSeen[s[0]-'a'][s[1]-'a'][s[2]-'a'] = true;
                        truncatedSeen[s[0]-'a'][s[1]-'a'] = true;
                    }
                }
            }
        }
        
        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}
