/*
    Author : Baptiste Prévost

    Idea : 
        - We loop over N, and keep track to new nodes and old nodes.
        - A list keeps track of the number of nodes that can reproduce k times, with 1 <= k <= K
        - At each step, the list is shifted, the front is dropped, and the new nodes are added to the back
*/

#include <iostream>
#include <list>
using namespace std;

int main() {
    unsigned int N, K;
    while(1) {
        cin >> N >> K;
        if(N == 0) break;
        if(K == 0) {
            cout << N-1 << endl;
            continue;
        }

        long long int totalNodes = 1, totalParents = 1, totalWeight = 0;
        list<long long int> parents;
        parents.push_back(1);

        for(unsigned int n = 0; n < N-1; n++) {
            totalWeight+=totalNodes;
            if(totalWeight >= 1234567890) break;
            totalNodes+=totalParents;
            parents.push_back(totalParents);
            totalParents = 2*totalParents;
            if(n >= K-1) {
                totalParents -= parents.front();
                parents.pop_front();
            }
        }
        cout << totalWeight << endl;
    }
    return 0;
}