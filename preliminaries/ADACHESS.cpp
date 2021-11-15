#include <iostream>
#include <utility>
#include <list>
using namespace std;

int abs(int a) {
    if(a>0) return a;
    return -a;
}

bool isFree(int* board, int x, int y, int initialX, int initialY) {
    if(x == initialX && y == initialY) return false;
    if(x >= 0 && x <= 7 && y >= 0 && y <= 7) {
        if(board[8*x + y] == 0) return true;
    }
    return false;
}

list<pair<int, int> > kingMoves(int* board, int x, int y, int initialX, int initialY) {
    list<pair<int, int> > ret;
    for(int i = -1; i < 2; i++) {
        for(int j = -1; j < 2; j++) {
            if(i == 0 && j == 0) continue;
            if(isFree(board, x+i, y+j, initialX, initialY)) ret.push_back(make_pair(x+i, y+j));
        }
    }
    return ret;
}

list<pair<int, int> > knightMoves(int* board, int x, int y, int initialX, int initialY) {
    list<pair<int, int> > ret;
    for(int i = -2; i < 3; i++) {
        for(int j = -2; j < 3; j++) {
            if(abs(i) + abs(j) == 3) {
                if(isFree(board, x+i, y+j, initialX, initialY)) ret.push_back(make_pair(x+i, y+j));
            }
        }
    }
    return ret;
}

list<pair<int, int> > towerMoves(int* board, int x, int y, int initialX, int initialY) {
    list<pair<int, int> > ret;
    for(int i = 0; i < 8; i++) {
        if(isFree(board, i, y, initialX, initialY)) ret.push_back(make_pair(i, y));
        if(isFree(board, x, i, initialX, initialY)) ret.push_back(make_pair(x, i));
    }
    return ret;
}

list<pair<int, int> > bishopMoves(int* board, int x, int y, int initialX, int initialY) {
    list<pair<int, int> > ret;
    for(int i = -7; i < 8; i++) {
        if(isFree(board, x+i, y+i, initialX, initialY)) ret.push_back(make_pair(x+i, y+i));
        if(isFree(board, x+i, y-i, initialX, initialY)) ret.push_back(make_pair(x+i, y-i));
    }
    return ret;
}

list<pair<int, int> > queenMoves(int* board, int x, int y, int initialX, int initialY) {
    list<pair<int, int> > ret, tM = towerMoves(board, x, y, initialX, initialY), bM = bishopMoves(board, x, y, initialX, initialY);;

    for(list<pair<int, int> >::iterator it = tM.begin(); it != tM.end(); it++) ret.push_back(*it);
    for(list<pair<int, int> >::iterator it = bM.begin(); it != bM.end(); it++) ret.push_back(*it);

    return ret;

}

list<pair<int, int> > getMoves(int* board, int f, int x, int y, int initialX, int initialY) {
    if(f == 0) return kingMoves(board, x, y, initialX, initialY);
    if(f == 1) return knightMoves(board, x, y, initialX, initialY);
    if(f == 2) return queenMoves(board, x, y, initialX, initialY);
    if(f == 3) return towerMoves(board, x, y, initialX, initialY);
    else return bishopMoves(board, x, y, initialX, initialY);
}

void compute(int* board, int f, int x, int y) {

    list<pair<int, int> > moves = getMoves(board, f, x, y, x, y);
    int step = 1;

    while(!moves.empty()) {
        list<pair<int, int> > nextMoves;
        for(list<pair<int, int> >::iterator it = moves.begin(); it != moves.end(); it++) board[8 * (*it).first + (*it).second] = step;
        for(list<pair<int, int> >::iterator it = moves.begin(); it != moves.end(); it++) {
            list<pair<int, int> > tempMoves = getMoves(board, f, (*it).first, (*it).second, x, y);
            for(list<pair<int, int> >::iterator it2 = tempMoves.begin(); it2 != tempMoves.end(); it2++) {
                    nextMoves.push_front(*it2);
            }
        }
        moves = nextMoves;
        step++;
    }
}

int main() {

    int T;
    int f, x, y, F, X, Y;
    scanf("%i\n", &T);
    for(int t = 0; t < T; t++) {
        int board[64];
        int BOARD[64];
        fill(board, board + 64, 0);
        fill(BOARD, BOARD + 64, 0);

        scanf("%i %i %i %i %i %i", &f, &x, &y, &F, &X, &Y);
        if(x==X && y==Y) {
            printf("0\n");
            continue;
        }

        if(f==4 && F==4) {
            if((abs(X-x)+abs(Y+y))%2==1) {
                printf("INF\n");
                continue;
            }
        }

        compute(board, f, x, y);
        compute(BOARD, F, X, Y);
        int min = 9;
        for(int i = 0; i < 8; i ++) {
            for(int j = 0; j < 8; j++) {
                if((board[8*i + j] != 0 || (i==x && j==y)) && (BOARD[8*i + j] != 0 || (i==X && j==Y))) {
                    if(min > board[8*i + j] + BOARD[8*i + j]) min = board[8*i + j] + BOARD[8*i + j];
                }
            }
        }
        printf("%i\n", min);

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