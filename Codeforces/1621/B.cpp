/*
    Author : Baptiste Prévost

    Idea :
        -
        -
*/

#include <iostream>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
typedef long long ll;

int l, r, c;
const int MAX = 1e9 + 1;

int main() {
    
    int t, n;
    cin >> t;

    while(t--) {
        int minL=MAX, maxR=0, costL=MAX, costR=MAX, maxLen=0, costLen=MAX, ans;
        cin >> n;
        forn(s, n) {
            cin >> l >> r >> c;
            if(l<minL) minL = l, costL = c;
            if(l==minL) costL = min(costL, c);
            if(r>maxR) maxR = r, costR = c;
            if(r==maxR) costR = min(costR, c);
            
            if(maxLen < r-l+1) maxLen = r-l+1, costLen = MAX;
            if(maxLen == r-l+1) costLen = min(costLen, c);

            ans = costL + costR;
            if(maxLen == maxR - minL + 1) ans = min(ans, costLen);
            cout << ans << endl;
            
        }
    }
}
