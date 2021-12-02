#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, z;
    int points[8] = {10, 8, 6, 5, 4, 3, 2, 1};
    string s;
    
    while(scanf("%i\n", &N)==1 && N!=0){
        for(int n = 0; n < N; n++) {
            string fullName, team;
            getline(cin, s); //skip name line
            getline(cin, s); //skip categories line
            
            for(int i = 0; i < 8; i++) {
                getline(cin, s);
                s = s.substr(5, s.length());
                fullName = s.substr(0, 25);
                team = s.substr(26, s.length()-1); team = team.substr(0, team.find(".")); //clean trim
             }
        }
    }

    return 0;
}