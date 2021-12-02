#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

int* customRotation(int triangle[3], int degree) {
    int* ret = (int*)malloc(3*sizeof(int));
    if(degree == 1) {
        ret[0] = triangle[1];
        ret[1] = triangle[2];
        ret[2] = triangle[0];
    } else if(degree == 2) {
        ret[0] = triangle[2];
        ret[1] = triangle[0];
        ret[2] = triangle[1];
    } else {
        ret[0] = triangle[0];
        ret[1] = triangle[1];
        ret[2] = triangle[2];
    }
    return ret;
}


int main() {
    vector<int*> triangles;
    vector<int*> triangles2;
    char c;
    do {
        triangles.clear();
        for(int i = 0; i < 6; i++) {
            int* triangle = (int*)malloc(3*sizeof(int));
            scanf("%i %i %i\n", triangle, triangle+1, triangle+2);
            triangles.push_back(triangle);
            triangles2.push_back(triangle);
        }
        scanf("%c", &c);

        int max = 0;
        int temp;
        int saveI, quotI, changed, degree;
        bool valid;
        do {
            for(int i = 0; i < pow(3, 6); i++) {
                valid = true; saveI = i;
                for(int j = 5; j >= 0; j--) {
                    degree = saveI/(int)pow(3,j);
                    triangles2[j] = customRotation(triangles[j], degree);
                    saveI -= degree*pow(3,j);
                }

                temp = 0; 
                for(int j = 0; j < 6; j++) {
                    if(triangles2[j][0] != triangles2[j==5 ? 0 : j+1][1]) {
                        valid = false;
                        i+=pow(3, j)-1;
                        break;
                    }
                    temp+=triangles2[j][2];
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