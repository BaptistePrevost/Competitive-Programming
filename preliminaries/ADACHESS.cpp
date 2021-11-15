#include <iostream>
using namespace std;

int abs(int a){
    if(a>0) return a;
    return -a;
}

int knightToKing(int x, int y, int X, int Y) { // 0 and 1
    if(x == X && y == Y) return 0;
    if(abs(X-x) + abs(y-Y) <= 2) return 1;
    
    int signX, signY;
    if(x>X) signX = -1; 
    else signX = 1;
    if(y>Y) signY = -1; 
    else signY = 1;

    if(abs(x-X) > abs(y-Y)) return 1 + knightToKing(x + signX*2, y + signY*1, X, Y);
    else return 1 + knightToKing(x + signX*1, y + signY*2, X, Y);
}

int knightToKnight(int x, int y, int X, int Y) { // 1 and 1
    if(x == X && y == Y) return 0;
    if(abs(x-X) + abs(y-Y) == 1) return 3;
    if(abs(x-X) + abs(y-Y) == 2) return 2; 

    int signX, signY;
    if(x>X) signX = -1; 
    else signX = 1;
    if(y>Y) signY = -1; 
    else signY = 1;

    if(abs(x-X) > abs(y-Y)) return 1 + knightToKnight(x + signX*2, y + signY*1, X, Y);
    else return 1 + knightToKnight(x + signX*1, y + signY*2, X, Y);

}

int knightToBishop(int x, int y, int X, int Y) { // 1 and 2
    if(abs(x-X) + abs(y-Y) == 3) return 1;
    else if(abs(x-X) == abs(y-Y)) return 1;
    else if((abs(x-X) + abs(y-Y)) % 2 == 0) return 2;
    
    int signX, signY;
    if(x>X) signX = -1; 
    else signX = 1;
    if(y>Y) signY = -1; 
    else signY = 1;

    if(abs(x-X) > abs(y-Y)) return 1 + knightToBishop(x + signX*2, y + signY*1, X, Y);
    else return 1 + knightToBishop(x + signX*1, y + signY*2, X, Y);

}



int main() {

    int usecases;
    scanf("%i\n", &usecases);
    int f, x, y, F, X, Y;

    for(int i = 0; i < usecases; i++) {
        scanf("%i %i %i %i %i %i\n", &f, &x, &y, &F, &X, &Y);
        
        if(x == X && y == Y) {
            printf("%i\n", 0);
            continue;
        }

        if(f == 0 && F == 0) {
            printf("%i\n", max(abs(X-x), abs(Y-y)));

        } else if ((f == 0 && F == 1) || (f == 1 && F == 0)) {
            printf("%i\n", knightToKing(x,y,X,Y));

        } else if ((f == 0 && F == 2) || (f == 2 && F == 0) ) {
            if(x == X || y == Y) printf("%i\n", abs(X-x));
            else if (abs(X-x) == abs(Y-y)) printf("%i\n", abs(X-x));
            else printf("%i\n", 2);

        } else if ((f == 0 && F == 3) || (f == 3 && F == 0)) {
            if(x-X == 0 || y-Y == 0) printf("%i\n", 1);
            else if (abs(X-x) == 1 && abs(Y-y) == 1) printf("%i\n", 1);
            else printf("%i\n", 2);

        } else if ((f == 0 && F == 4) || (f == 4 && F == 0)) {
            if(abs(X-x) <= 1 && abs(Y-y) <= 1) printf("%i\n", 1);
            else if (abs(X-x) == abs(Y-y)) printf("%i\n", 1);
            else if(abs(abs(X-x) - abs(Y-y)) == 1) printf("%i\n", 2);
            else printf("%i\n", 2+(abs(X-x) + abs(Y-y))%2);

        } else if (f == 1 && F == 1) {
            printf("%i\n", knightToKnight(x,y,X,Y));

        } else if ((f == 1 && F == 2) || (f == 2 && F == 1)) {
            if(abs(x-X) + abs(y-Y) == 3) printf("%i\n", 1);
            else if(abs(x-X) == abs(y-Y)) printf("%i\n", 1);
            else if (x == X || y == Y) printf("%i\n", 1);
            else printf("%i\n", 2);

        } else if ((f == 1 && F == 3) || (f == 3 && F == 1)) {
            if(abs(x-X) + abs(y-Y) == 3) printf("%i\n", 1);
            else if (x == X || y == Y) printf("%i\n", 1);
            else printf("%i\n", 2);

        } else if ((f == 1 && F == 4) || (f == 4 && F == 1)) {
            printf("%i\n", knightToBishop(x,y,X,Y));

        } else if (f == 2 && F == 2) {
            if(abs(X-x) == 0 || abs(Y-y) == 0) printf("%i\n", 1);
            else if (abs(X-x) == abs(Y-y)) printf("%i\n", 1);
            else printf("%i\n", 2);

        } else if ((f == 2 && F == 3) || (f == 3 && F == 2)) {
            if(abs(X-x) == 0 || abs(Y-y) == 0) printf("%i\n", 1);
            else if (abs(X-x) == abs(Y-y)) printf("%i\n", 1);
            else printf("%i\n", 2);

        } else if ((f == 2 && F == 4) || (f == 4 && F == 2)) {
            if(abs(X-x) == 0 || abs(Y-y) == 0) printf("%i\n", 1);
            else if (abs(X-x) == abs(Y-y)) printf("%i\n", 1);
            else printf("%i\n", 2);

        } else if (f == 3 && F == 3) {
            if(abs(X-x) == 0 || abs(Y-y) == 0) printf("%i\n", 1);
            else printf("%i\n", 2);

        } else if ((f == 3 && F == 4) || (f == 4 && F == 3)) {
            if(abs(X-x) == 0 || abs(Y-y) == 0) printf("%i\n", 1);
            else if (abs(X-x) == abs(Y-y)) printf("%i\n", 1);
            else printf("%i\n", 2);

        } else if (f == 4 && F == 4) {
            if((abs(X-x) + abs(Y-y))%2 == 1) printf("%s\n", "INF");
            else if (abs(X-x) == abs(Y-y)) printf("%i\n", 1);
            else printf("%i\n", 2);
        }
    }


    return 0;
}

/*
0 - King
1 - Knight
2 - Queen
3 - Tower
4 - Bishop
*/

/*
Input
5
1 0 0 1 7 7
2 1 3 3 2 5 
0 1 0 4 5 5
3 1 1 4 3 3
0 1 2 0 3 4

Output
6
2
2
1
2

Input
10
2 3 6 1 6 2
3 3 6 3 6 7
4 4 6 4 2 4
3 6 0 4 1 0
3 7 1 3 5 2
0 0 6 1 5 4
0 5 7 3 3 5
0 4 1 4 5 3
3 2 1 3 4 2
0 5 2 0 2 7

Output
2
2
1
1
2
3
2
2
2
5
*/