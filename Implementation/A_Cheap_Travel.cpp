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
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if(b<=a*m) {
        cout << n/m*b + min(n%m*a, b);
    } else cout << a*n;
    return 0;
}
