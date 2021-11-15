#include <iostream>
#include <list>
#include <utility>
#include <stdio.h>
#include <cstdlib>
using namespace std;

list<pair<int, pair<int, int> > > listTriplets(int* triangles[6], int indices[3]) {
    list<pair<int, pair<int, int> > > ret;
    int center, left, right;
    int c1, c2;
    int comb1[3] = {1, 0, 2}, comb2[3] = {2, 0, 1}, comb3[3] = {0, 1, 2}, comb4[3] = {2, 1, 0}, comb5[3] = {0, 2, 1}, comb6[3] = {1, 2, 0};
    int* combinations[6] = {comb1, comb2, comb3, comb4, comb5, comb6};

    for(int k = 0; k < 3; k++) {
        c1 = k;
        c2 = (k+1)%3;
        for(int c = 0; c < 3; c++) {
            for(int l = 0; l < 6; l++) {
                left = combinations[l][0]; center = combinations[l][1]; right = combinations[l][2];
                if(triangles[indices[center]][c1] == triangles[indices[left]][c]) {
                for(int d = 0; d < 3; d++) {
                    if(triangles[indices[center]][c2] == triangles[indices[right]][d]) {
                        ret.push_front(make_pair(triangles[indices[left]][(c+1)%3] + triangles[indices[center]][(c1+2)%3] + triangles[indices[right]][(d+2)%3], make_pair((triangles[indices[left]][(c+2)%3]), (triangles[indices[right]][(d+1)%3]))));
                    }
                }
            }
            }
        }
    }
    return ret;
}

int main() {
    int* triangles[6];
    char c;

    do {
        for(int i = 0; i < 6; i++) {
            int* triangle = (int*)malloc(3*sizeof(int));
            scanf("%i %i %i\n", triangle, triangle+1, triangle+2);
            triangles[i] = triangle;
        }
        scanf("%c", &c);

        int* ind1 = (int*)malloc(3*sizeof(int));
        int* ind2 = (int*)malloc(3*sizeof(int));
        int max = 0;
        for(int i = 0; i < 4; i++) {
            ind1[0] = i;
            for(int j = i+1; j < 5; j++) {
                ind1[1] = j;
                for(int k = j+1; k < 6; k++) {
                    ind1[2] = k;
                    bool test;
                    int index = 0;
                    for(int x = 0; x < 6; x++) {
                        test = true;
                        for(int y = 0; y < 3; y++) if(ind1[y] == x) test = false;
                        if(test) {ind2[index]=x; index++;}
                    }
                    list<pair<int, pair<int, int> > > t1 = listTriplets(triangles, ind1);
                    list<pair<int, pair<int, int> > > t2 = listTriplets(triangles, ind2);
                    for(list<pair<int, pair<int, int> > >::iterator it1 = t1.begin(); it1 != t1.end(); it1++) {
                        for(list<pair<int, pair<int, int> > >::iterator it2 = t2.begin(); it2 != t2.end(); it2++) {
                            if((*it1).second.first == (*it2).second.second && (*it1).second.second == (*it2).second.first) {
                                if(max < (*it1).first + (*it2).first) max = (*it1).first + (*it2).first;
                            }
                        }
                    }
                }
            }
        }
        if(max > 0) printf("%i\n", max);
        else printf("none\n");
    } while(c != '$');
    return 0;
}

/*
Input
1 4 20 
3 1 5 
50 2 3 
5 2 7 
7 5 20 
4 7 50 
* 
10 1 20 
20 2 30 
30 3 40 
40 4 50 
50 5 60 
60 6 10 
* 
10 1 20 
20 2 30 
30 3 40 
40 4 50 
50 5 60 
10 6 60 
$

Output
152 
21 
none
*/