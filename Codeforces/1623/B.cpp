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
typedef long long ll;

int main() {
    int t, n, l, r, d;
    list<pair<int, int> > ra;
    list<pair<int, int> >::iterator it;
    bool picked[1001];
    int ans[10001];

    cin >> t;

    while(t--) {
        cin >> n;
        ra.clear();
        forn(i, n+1) {
            picked[i]=false;
            ans[i]=-1;
        }
        forn(i, n) {
            cin >> l >> r;
            it = ra.begin();
            while(it != ra.end() && it->second - it->first < r-l) it++;
            ra.insert(it, make_pair(l, r));
        }
        
        int j=0;
        for(auto p: ra) {
            for(int i=p.first; i <= p.second; i++) {
                if(!picked[i]) {
                    picked[i]=true;
                    ans[j]=i;
                    break;
                }
            }
            j++;
        }
        it = ra.begin();
        forn(i, n) {
            cout << it->first << " " << it->second << " " << ans[i] << endl;
            it++;
        }
    }

    return 0;
}
