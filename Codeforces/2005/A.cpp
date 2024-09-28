/*
    Problem : https://codeforces.com/contest/2005/A
    Author : Baptiste Prévost
    Subjects :

    Idea : Same letters have to be grouped to minimize palindrom subsequences.
    Moreover, the number of palidrom subsequences in a group of identic letters is polynomial in the group size.
    The solution has to minimize the largest group.

    Complexity : n
*/

#include <bits/stdc++.h>
#include <vector>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;


int main() {
    int t;
    cin >> t;

    string s = "aeiou";

    int n;
    while(t--) {
        cin >> n;
        for(int i=0; i<5; i++) {
            for(int j=i; j<n; j+=5) cout << s[i];
        }

        cout << endl;
    }
}
