/*
    Author : Baptiste Prévost

    Idea :
        -
        -
*/

#include <iostream>
#include <list>
#include <queue>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
typedef long long ll;

const int N = 300050;
int c[N], parent[N], cnt[N];
list<int> vert[N], vert2[N];


void dfs(int x, int origin) {
    parent[x]=origin;
    for(auto y : vert[x]) {
        if(y!=origin) {
            dfs(y,x);
            cnt[x] += cnt[y];
        }
    }
    cnt[x] += c[x];
}

int main() {

    int n;
    scanf("%i", &n);
    forn(i,n) {
        scanf("%i", c + i);
    }

    int u,v;
    forn(i,n-1) {
        scanf("%i %i", &u, &v);
        u--; v--;
        vert[u].push_back(v);
        vert[v].push_back(u);   
    }
    
    dfs(0, -1);

    forn(i, n) {
        for(auto j : vert[i]) {
            if(i==parent[j]) {
                if(c[i] || cnt[0]-cnt[j]>1) {
                    vert2[i].push_back(j);
                }
            } else {
                if(c[i]==1 || cnt[i]>1) {
                    vert2[i].push_front(j);
                }
            }
        }
    }
    
    queue<int> q;
    forn(i, n) {
        if(c[i]==1) q.push(i);
    }

    while(!q.empty()) {
        int current = q.front();
        q.pop();
        c[current]=1;
        for(auto j : vert2[current]) {
            if(c[j]!=1) q.push(j);
        }
    }

    forn(i, n) printf("%i ", c[i]);

    return 0;
}
