/*
    Author : Baptiste Prévost

    Idea : 
        - 
        -
*/

#include <iostream>
#include <map>
#include <list>
#include <algorithm>
using namespace std;

int main() {

    list<pair<int, int> > history[500001];
    list<pair<int, int> > seq;
    for(int i = 1; i < 500001; i++) {
        history[i].push_back(make_pair(0, i));
    }
    
    int q, a, x, y;
    for(int i=0; i<q; i++){
        cin >> a;
        if(a==1) {
            cin >> x;
            seq.push_back(make_pair(x, i));
        } else {
            cin >> x >> y;
            history[x].push_back(make_pair(q, y));
        }
    }

    for(list<pair<int, int> >::iterator it = seq.begin(); it != seq.end(); it++) {
        int ret = it->first;
        list<pair<int, int> >::iterator it2 = history[ret].end();
        while() {
            if(it2 == history[ret].begin()) break;
        }
    }
}