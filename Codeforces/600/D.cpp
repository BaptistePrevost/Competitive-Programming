/*
    Problem : 
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

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)

long double PI = 3.14159265358979323846;
int main() {
    long double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;

    long double ans = 0;
    long double d = sqrtl((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    if(r1<=r2 && d+r1 <= r2) ans = PI*r1*r1;
    else if(r2 <= r1 && d+r2 <= r1) ans = PI*r2*r2;
    else if(d < r1 + r2) {
        long double theta1 = acos((r1*r1+d*d-r2*r2)/(2*r1*d));
        long double theta2 = acos((r2*r2+d*d-r1*r1)/(2*r2*d));
        long double sector1 = theta1*r1*r1;
        long double sector2 = theta2*r2*r2;
        long double triangle1 = 0.5*r1*r1*sin(2*theta1);
        long double triangle2 = 0.5*r2*r2*sin(2*theta2);
        ans = (sector1-triangle1) + (sector2-triangle2);
    }

    cout << fixed << setprecision(8);
    cout << ans << endl;

    return 0;
}
