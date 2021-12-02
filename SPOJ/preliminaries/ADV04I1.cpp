#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;

typedef vector<bool> column;
typedef vector <vector <bool> > graph;
typedef vector <vector <vector <bool > > > graphSet;
typedef vector <vector <vector <bool > > >::iterator graphSetIterator;

int mem[101];
graphSet* memSet[101];

int countTotal(int n) {
    if(n==1) return 1;

    int ret = 1;
    for(int i = 1; i < n; i++) {
        ret+= mem[i] ? mem[i] : countTotal(i);
        if(i>n/2) ret-= mem[i-1] ? mem[i-1] : countTotal(i-1);
    }
    mem[n] = ret;
    return ret;
}

graphSet* getGraphs(int n) {
    graphSet* ret = (graphSet*)malloc(sizeof(graphSet));

    if(n==1) {
        column* col = (column*)malloc(sizeof(column));
        col->push_back(true);
        graph* newGraph1 = (graph*)malloc(sizeof(graph));
        newGraph1->push_back(*col);
        ret->push_back(*newGraph1);
    } else {
        graphSet* previousGraphSet = (graphSet*)malloc(sizeof(graphSet));
        if(memSet[n-1] != nullptr) previousGraphSet = memSet[n-1];
        else previousGraphSet = getGraphs(n-1);
        for(graphSetIterator it = (*previousGraphSet).begin(); it != (*previousGraphSet).end(); it++ ) {
            for(int j = 0; j < (*it).size(); j++) { //for each column
                graph* newGraph2 = (graph*)malloc(sizeof(graph));
                *newGraph2 = *it;
                (*newGraph2)[j].push_back(true);//can't do this line the second? Pbly because declaring in a loop
                ret->push_back(*newGraph2);
            }
            graph* newGraph3 = (graph*)malloc(sizeof(graph));
            *newGraph3 = *it;
            column* newCol = (column*)malloc(sizeof(column));
            newCol->push_back(true);
            newGraph3->push_back(*newCol);
            ret->push_back(*newGraph3);
        }
    }
    memSet[n] = ret;
    return ret;
}

//   // Create lists
//   std::list<char> A = {'a','b'};
//   std::list<char> B = {'c','d'};

//   // Insert A at the beginning of B
//   copy(A.rbegin(), A.rend(), front_inserter(B));

list <list <int> > MEM[101];

list <list <int> > getEverything(int n) {
    if(MEM[n].size() > 0) return MEM[n];
    // printf("Calculating %i\n", n);
    list< list<int> > ret;
    list<int> newGraph1;
    newGraph1.push_front(n);
    ret.push_back(newGraph1);
    int bound = n == 2 ? 1 : n/2 + 1;
    for(int i = 1; i < bound; i++) {
        // list <list <int> > smallers = MEM[i].size() > 0 ? MEM[i] : getEverything(i);
        list <list <int> > smallers;
        if(MEM[i].size() > 0 ) {
            // printf("Getting memorized for %i\n", i);
            smallers = MEM[i];
        } else smallers = getEverything(i);
        for(list <list <int> >::iterator it = smallers.begin(); it != smallers.end(); it++) {
            if((*it).front() <= n-i) {
                list<int> newGraph2;
                newGraph2.push_back(n-i);
                while(!(*it).empty()) {
                    newGraph2.push_back((*it).front());
                    (*it).pop_front();
                }
                ret.push_back(newGraph2);
            }
        }
    }
    // printf("Memorizing %i\n", n);
    MEM[n] = ret;
    return ret;
}

int main() {

    fill(memSet, memSet+101, nullptr);
    list <list <int> > emptyGraph;
    fill(MEM, MEM+101, emptyGraph);
    int T, n;

    cin >> T;
    while(T--) {
        cin >> n;
        
        if(n%2 == 1) {
            printf("0\n");
            continue;
        }

    }

    // for(int i = 1; i < 7; i++) {
    //     printf("\n*** %i ***\n", i);
    //     graphSet* result = getGraphs(i);
    //     for(graphSetIterator it = (*result).begin(); it != (*result).end(); it++ ) {
    //         for(int i = 0; i < (*it).size() ; i++) { //for each graph
    //             for(int j = 0; j < (*it)[i].size(); j++) { //for each column
    //                 printf("1 ");
    //             }
    //             printf("\n");
    //         }
    //         printf("\n");
    //     }
    // }
    for(int u = 0; u <= 100; u++) {
        for(int i = 1; i <= 100; i++) {
            // printf("[%i] %i\n", i, getEverything(i).size());
            getEverything(i);
        }
    }


    return 0;
}