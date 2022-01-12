/*
    Author : Baptiste Prévost

    Idea :
        -
        -
*/

#include <iostream>
#include <utility>
#include <list>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
typedef unsigned long long ll;

int main() {
    int t;
    cin >> t;

    while(t--) {
        ll n, snow, mini = 1e9, ans=0;
        cin >> n;
        forn(i, n) {
            forn(j, n) cin >> snow;
            for(int j = n; j < 2*n; j++) {
                cin >> snow;
                if(i==0 && j==n) mini = min(snow, mini);
                else if(i==0 && j==2*n-1) mini = min(snow, mini);
                else if(i==n-1 && j==n) mini = min(snow, mini);
                else if(i==n-1 && j==2*n-1) mini = min(snow, mini);
            }
        }
        
        for(int i=n; i<2*n; i++) {
            forn(j, n){
                cin >> snow;
                if(i==n && j==0) mini = min(snow, mini);
                else if(i==n && j==n-1) mini = min(snow, mini);
                else if(i==2*n-1 && j==0) mini = min(snow, mini);
                else if(i==2*n-1 && j==n-1) mini = min(snow, mini);
            }
            for(int j = n; j < 2*n; j++) {
                cin >> snow;
                ans+=snow;
            }

        }
        ans+=mini;
        cout << ans << endl;
    }

    return 0;
}
