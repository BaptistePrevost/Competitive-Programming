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
    int n, k;
    cin >> n >> k;
    while(k--) {
        if(n%10) n--;
        else n/=10;
    }
    cout << n;
}
