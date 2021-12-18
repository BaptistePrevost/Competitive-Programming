/*
    Author : Baptiste Prévost

    Idea : 
        - Build a graph of players, where an edge from A to B means 'A is beaten by B'
        - Beginning from the original winners, perform a DFS to find every possible winner
        
        - NOTE : WA, but I'm certain the idea is right
*/

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    int t, n, f;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<pair<int, int > > m1, m2; //stores strength/player
        vector<int > rm1, rm2; //stores index in sort
        // vector<list<int > > adj;
        vector<int> wins;
        for(int i=0; i<n; i++) {
            cin >> f;
            m1.push_back(make_pair(f, i));
            wins.push_back(0);
            rm1.push_back(i);
        }
        for(int i=0; i<n; i++) {
            cin >> f;
            m2.push_back(make_pair(f, i));
            rm2.push_back(i);
        }
        
        sort(m1.begin(), m1.end(), [](auto &left, auto &right) {
            return left.first > right.first;
        });

        sort(m2.begin(), m2.end(), [](auto &left, auto &right) {
            return left.first > right.first;
        });

        for(int i=0; i<n; i++){
            rm1[m1[i].second] = i;
            rm2[m2[i].second] = i;
        }

        list<int> queue;
        queue.push_back(m1[0].second);
        queue.push_back(m2[0].second);
        wins[m1[0].second] = 1;
        wins[m2[0].second] = 1;

        int current;
        while(!queue.empty()){
            current = queue.front();
            queue.pop_front();
            for(int i=rm1[current]-1; i>=0; i--) {
                if(wins[m1[i].second] == 0) {
                    wins[m1[i].second] = 1;
                    queue.push_back(wins[m1[i].second]);
                }
            }
            for(int i=rm2[current]-1; i>=0; i--) {
                if(wins[m2[i].second] == 0) {
                    wins[m2[i].second] = 1;
                    queue.push_back(wins[m2[i].second]);
                }
            }
        }

        for(int i=0; i<n; i++){
            cout<<wins[i];
        }

        cout<<endl;
    }

    return 0;
}