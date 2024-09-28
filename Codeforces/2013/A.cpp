/*
    Problem : https://codeforces.com/contest/2013/problem/A
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
    int t;
    cin >> t;

    ll n, x, y;
    while(t--) {
        cin >> n >> x >> y;
        ll ans;
        if(y <= x) {
            ans = n/y + (n%y > 0);
        } else {
            ans = n/y;
            ll rest = (n/y)*y - (n/y)*x + n%y;
            ans += rest/x + (rest%x > 0);
        }
        cout << ans << endl;
    }
}
