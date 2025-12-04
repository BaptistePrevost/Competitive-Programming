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

int main() {
    string s;
    cin >> s;
    if(s.find('A')  != string::npos && s.find('B')  != string::npos && s.find('C')  != string::npos )
    cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
