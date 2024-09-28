/*
    Problem : https://codeforces.com/contest/2008/problem/D
    Author : Baptiste Prévost
    Subjects : DSU

    Idea :

    Complexity :
*/

#include <iostream>
#include <vector>

using namespace std;

struct DSU {
        vector<int> parent;
        vector<int> size;

        void init(int n) {
            parent.resize(n);
            size.resize(n);
            for(int i=0; i<n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        //With path compression optimisation
        int find(int a) {
            if(a == parent[a]) return a;
            return parent[a] = find(parent[a]);
        }

        //With size balance optimisation
        void merge(int a, int b) {
            a = find(a);
            b = find(b);
            if(a != b) {
                if(size[a] < size[b]) swap(a,b);
                parent[b] = a;
                size[a] += size[b];
            }
        }

};


int main() {
    int t, n, v;
    char c;
    vector<int> blackCount;
    DSU dsu;
    cin >> t;
    while(t--) {
        cin >> n;
        if(n==0) continue;
        dsu.init(n);
        for(int i=0; i<n; i++) {
            cin >> v;
            v--;
            dsu.merge(i, v);
        }

        blackCount.resize(n);
        for(int i=0; i<n; i++) blackCount[i] = 0;
        for(int i=0; i<n; i++) {
            cin >> c;
            if(c=='0') {
                blackCount[dsu.find(i)]++;
            }
        }
        for(int i=0; i<n; i++) {
            cout << blackCount[dsu.find(i)] << " ";
        }
        cout << endl;
    }
}