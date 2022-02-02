/*
    Author : Baptiste Prévost

    Idea :
        -
        -
*/

#include<bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
typedef long long ll;
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
int main() {
    ll n, k, count=0;
    cin>>n>>k;
    string s;
    cin >> s;
    vector<ll> v(26,-1);
    for(char c='a'; c<='z'&&count<k; c++) {
        ll i=0;
        for(;i<n;++i){
            if(s[i]==c) ++count;
            if(count==k) break;
        }
        v[c-'a']=i;
    }
    for(ll i=0; i<n; ++i) {
        if(i>v[s[i]-'a']) cout<<s[i];
    }
    return 0;
}
