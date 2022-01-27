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
    string s;
    int lucky=0;
    cin >> s;
    for(auto c: s) {
        if(c=='4' || c=='7') lucky++; 
    }
    if(lucky==4 || lucky==7) cout << "YES";
    else cout << "NO";
    return 0;
}