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

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int ans = 0;
    forn(i, s1.length()) {
        if(s1[i]>90) s1[i]-=32;
        if(s2[i]>90) s2[i]-=32;
        if(s1[i]<s2[i]) {ans=-1; break;}
        if(s1[i]>s2[i]) {ans=1; break;}
    }
    cout << ans;
    return 0;
}
