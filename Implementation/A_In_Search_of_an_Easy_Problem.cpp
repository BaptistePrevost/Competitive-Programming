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
    int n, i;
    string ans = "EASY";
    cin >> n;
    while(n--) {
        cin >> i;
        if(i==1) {
            ans="HARD";
            break;
        }
    }
    cout << ans;

    return 0;
}
