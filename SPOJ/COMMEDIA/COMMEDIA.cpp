/*
    Author : Baptiste Prévost

    Idea : 
        - The idea is the same as the 2D Lloyd's puzzle. It is about the parity of the permutations.
        - You can see the cube as a 3D chessboard with white and black boxes (even and odd), to highlight the parity of the initial permutation
        - In the initial permutation, we use the position of the empty cube (0) to calculate the number of moves (transpositions) necessary to reach this permutation from the base one.
        - The parity of this number is the signature of a reachable permutation with the empty cube located here. This signature is independant from the moves (=transpositions) we decided to perform to obtain a permutation from another.
        - Then, by counting the length of each cycle in the initial  puzzle, we evaluate the signature of the initial permutation.
        - The puzzle is solvable if and only if this two signatures are compatible.
*/

#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N;
    int cubes[1000001], nbPermutations;
    bool done[1000001];
    int parity;
    while(N--) {
        cin >> M;
        for(int z = 0; z < M; z++) {
            for(int y = 0; y < M; y++) {
                for(int x = 0; x < M; x++) {
                    cin >> cubes[z*M*M + y*M + x];
                    done[z*M*M + y*M + x] = false;
                    if(cubes[z*M*M + y*M + x] == 0) {
                        parity = (M-1-x + M-1-y + M-1-z)%2;
                        cubes[z*M*M + y*M + x] = M*M*M; //replace 0 with M*M*M
                    }
                }
            }
        }

        nbPermutations = 0;
        for(int i = 0; i < M*M*M; i++) {
            if(!done[i]) {
                done[i] = true;
                int next = cubes[i]-1;
                while(next != i) {
                    nbPermutations++;
                    done[next] = true;
                    next = cubes[next]-1;
                }
            }
        }

        if((nbPermutations)%2 == parity) cout << "Puzzle can be solved." << endl;
        else cout << "Puzzle is unsolvable." << endl;
    }
    return 0;
}