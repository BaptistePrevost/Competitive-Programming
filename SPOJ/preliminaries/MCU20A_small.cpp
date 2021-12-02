#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
    vector<int*> triangles;
    char c;
    do {
        triangles.clear();
        for(int i = 0; i < 6; i++) {
            int* triangle = (int*)malloc(3*sizeof(int));
            scanf("%i %i %i\n", triangle, triangle+1, triangle+2);
            triangles.push_back(triangle);
        }
        scanf("%c", &c);

        int max = 0;
        int temp;
        bool valid;
        do {
            for(int i = 0; i < pow(3, 6); i++) {
                temp=0; valid = true;
                for(int j = 0; j < 6; j++) {
                    if(i%(int)pow(3, j+1) == 1*(int)pow(3, j) || i%(int)pow(3, j+1) == 2*(int)pow(3, j)) {
                        rotate(triangles[j], triangles[j]+1, triangles[j]+3);
                    }
                }
                for(int i = 0; i < 6; i++) {
                    if(triangles[i][0] != triangles[i==5 ? 0 : i+1][1]) {
                        valid = false;
                        break;
                    }
                    temp+=triangles[i][2];
                }
                if(valid && max < temp) max = temp;
            }
            
        } while(next_permutation(triangles.begin(), triangles.end()));

        if(max) printf("%i\n", max);
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