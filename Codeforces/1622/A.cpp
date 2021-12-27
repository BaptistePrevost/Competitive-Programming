/*
    Author : Baptiste Prévost

    Idea :
        - The broken pieces may built two opposites edges, or two edges side to side
*/

#include <iostream>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long longw

int main() {
    int t, l1, l2, l3;
    cin >> t;
    while(t--) {

        cin >> l1 >> l2 >> l3;
        if(l1+l2==l3 || l1+l3==l2 || l1==l2+l3) cout << "YES" << endl;
        else if ((l1==l2 && l3%2==0) || (l1==l3 && l2%2==0) || (l2==l3 && l1%2==0)) cout << "YES" << endl;
        else cout << "NO" << endl;

    }

    return 0;
}
