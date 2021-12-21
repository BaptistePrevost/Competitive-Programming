/*
    Author : Baptiste Prévost

    Idea : 
        - Store and read the instructions in the inversed order
*/

#include <iostream>
#include <map>
#include <utility>
#include <list>
using namespace std;

int main() {
    int n, a, b, c;
    list<int> res;
    int value[500001];
    pair<int, int> instructions[500001];

    for(int i=0; i<500001; i++) {
        value[i]=i;
    }

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a;
        if(a==1) {
            cin >> b;
            c=0;
        } else {
            cin >> b >> c;
        }
        instructions[n-i-1] = make_pair(b,c);
    }


    for(int i = 0; i<n; i++) {
        if(instructions[i].second == 0) {
            res.push_front(value[instructions[i].first]);
        } else {
            value[instructions[i].first] = value[instructions[i].second];
        }
    }

    for(list<int>::iterator it = res.begin(); it != res.end(); it++) {
        cout << *it << ' ';
    }
}