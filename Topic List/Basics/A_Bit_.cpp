/*
    Author : Baptiste Prévost

    Idea :
        -
        -
*/

#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
typedef long long ll;

int main() {
    int n, X=0;
    cin >> n;

    forn(i, n) {
        string s;
        cin >> s;
        if(s[1]=='-') X--;
        else X++;
    }
    cout << X << endl;
    return 0;
}
