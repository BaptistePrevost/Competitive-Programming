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
    int notes[1000][5] = {};
    int n, m, ans=0;
    string answer;
    cin >> n >> m;
    forn(i,n) {
        cin >> answer;
        forn(j,m) {
            notes[j][answer[j]-65]++;
        }
    }
    forn(j,m) {
        int maxi=0;
        forn(k,5) {
            if(notes[j][k]>maxi) maxi=notes[j][k];
        }
        scanf("%d", &n);
        ans+=n*maxi;
    }
    cout << ans;
    return 0;
}
