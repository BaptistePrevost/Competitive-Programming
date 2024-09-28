/*
    Problem : https://codeforces.com/contest/problem/B
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

int main() {
    ll t;
    cin >> t;

    ll n, a;
    while(t--) {
        cin >> n;
        ll minus = 0;
        for(int i=0; i<n-2; i++) {
            cin >> a;
            minus -= a;
        }
        cin >> a;
        minus += a;
        cin >> a;
        
        cout << a - minus << endl;
    }
}
