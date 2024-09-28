/*
    Problem : https://codeforces.com/contest/2013/problem/F1
    Author : Baptiste Prévost
    Subjects : game theory, recursion

    Idea : It is a two players game with turns. Alice starts and wins 
    if there is a winning strategy. This can be determined by performing all moves,
    and see if one move leads to a situation where its Bob's turn and he can't ever
    win, i.e the opposite situation. This can be done recursively.

    Complexity : 
*/

#include <bits/stdc++.h>
#include <vector>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;

vector<vector<int>> adj;
vector<bool> visited;

bool doesBobWin(int aliceNode, int bobNode);
bool doesAliceWin(int aliceNode, int bobNode) {
    for(int aliceNextNode : adj[aliceNode]) {
        if(visited[aliceNextNode]) continue;
        visited[aliceNextNode] = true;
        if(!doesBobWin(aliceNextNode, bobNode)) {
            visited[aliceNextNode] = false;
            return true;
        }
        visited[aliceNextNode] = false;
    }
    return false;
}

bool doesBobWin(int aliceNode, int bobNode) {
    for(int bobNextNode : adj[bobNode]) {
        if(visited[bobNextNode]) continue;
        visited[bobNextNode] = true;
        if(!doesAliceWin(aliceNode, bobNextNode)) {
            visited[bobNextNode] = false;
            return true;
        }
        visited[bobNextNode] = false;
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    int n, a, b, u, v;
    while(t--) {
        cin >> n;

        adj = vector<vector<int>>(n+1, vector<int>());
        for(int i=0; i<n-1; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        cin >> u >> v;
        visited = vector<bool>(n+1, false);
        visited[1] = true;
        visited[u] = true;

        if(doesAliceWin(1, u)) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
}
