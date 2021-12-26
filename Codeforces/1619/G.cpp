/*
    Author : Baptiste Prévost

    Idea : 
        - Simple DFS
*/

#include <iostream>
#include <cstdlib>
#include <list>
#include <utility>
#include <algorithm>
#include <map>
#include "math.h"
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long

struct Bomb;

struct Bomb{
    ll x, y, z;
    bool visited;
};


int main() {
    int t, n, k, x, y, z;
    cin >> t;
    Bomb* ptr;

    map<ll, list<Bomb*> > bX, bY;
    map<Bomb*, list<Bomb*>> adj;
    list<Bomb*> bombs;
    list<ll> times;

    while(t--) {
        bX.clear(); bY.clear();
        adj.clear();
        bombs.clear();
        times.clear();
        cin >> n >> k;
        forn(i, n) {
            ptr = (Bomb*)malloc(sizeof(Bomb));
            cin >> x >> y >> z;
            ptr->x = x; ptr->y = y; ptr->z = z;
            ptr->visited = false;
            bombs.push_back(ptr);


            for(list<Bomb*>::iterator it = bX[x].begin(); it!=bX[x].end(); it++) {
                Bomb* b = *it;
                if(abs(b->y-y)<=k) {
                    adj[b].push_back(ptr);
                    adj[ptr].push_back(b);
                }

            }

            for(list<Bomb*>::iterator it = bY[y].begin(); it!=bY[y].end(); it++) {
                Bomb* b = *it;
                if(abs(b->x-x)<=k) {
                    adj[b].push_back(ptr);
                    adj[ptr].push_back(b);
                }
            }

            bX[x].push_back(ptr);
            bY[y].push_back(ptr);
        }

        for(Bomb* b: bombs) {
            if(!b->visited) {
                b->visited = true;
                list<Bomb*> queue;
                Bomb* current = b;
                ll minZ = b->z;
                queue.push_back(current);

                while(!queue.empty()) {
                    current = queue.front();
                    queue.pop_front();
                    
                    for(Bomb* c : adj[current]) {
                        if(!c->visited) {
                            c->visited = true;
                            z = min(minZ, c->z);
                            queue.push_back(c);
                        }
                    }
                }

                times.push_back(minZ);
            }
        }

        times.sort();
        ll tick = 0;
        while(tick+1 < times.size()) {
            while(!times.empty() && times.front() <= tick) times.pop_front();
            if(times.empty() || tick+1 >= times.size()) break;
            tick++;
        }

        cout << tick << endl;
    }

    return 0;
}