#include<bits/stdc++.h>
using namespace std;

vector<vector< int > > adj;
int n;


/*
    Most simple recursive implementation
*/
vector<int> visited;

void dfs(int v) {
    visited[v]=true;
    for(int u : adj[v]) {
        if(!visited[u]) {
            dfs(u);
        }
    }
}

/*
    Compute entry and exit times
    Color is 0 if unvisited, 1 if visited, and 2 if exited
*/

vector<int> color;
vector<int> time_in, time_out;
int dfs_timer = 0;

void dfs(int v) {
    time_in[v] = dfs_timer++;
    color[v]=1;
    for(int u : adj[v]) {
        if(color[u]==0) {
            dfs(u);
        }
    }
    color[v]=2;
    time_out[v] = dfs_timer++;
}