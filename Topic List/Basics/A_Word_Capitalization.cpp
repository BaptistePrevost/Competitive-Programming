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
    cin >> s;
    if(s[0]>90) s[0]-=32;
    cout << s;
    return 0;
}