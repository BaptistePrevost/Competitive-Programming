/*
    Author : Baptiste Prévost

    Idea :
        - Keep the original order, add a suborder after the likes and dislikes
*/

#include <iostream>
#include <list>
#include <utility>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long

int main() {
    int t, n, p[200001];
    list<pair<int, int> > bad, good;
    string s;
    cin >> t;
    
    while(t--) {
        bad.clear(); good.clear();
        cin >> n;
        forn(i, n) {
            cin >> p[i];
        }

        cin >> s;

        forn(i, n) {
            if(s[i] == '0') {
                bad.push_back(make_pair(p[i], i));
            } else good.push_back(make_pair(p[i], i));
        }

        good.sort(); bad.sort();

        int i=0;
        for(list<pair<int, int> >::iterator it = bad.begin(); it!= bad.end(); it++) {
            p[it->second] = i;
            i++;
        }

        for(list<pair<int, int> >::iterator it = good.begin(); it!= good.end(); it++) {
            p[it->second] = i;
            i++;
        }

        forn(i, n) {
            cout << p[i]+1 << " ";
        }
        cout << endl;

    }

    return 0;
}
