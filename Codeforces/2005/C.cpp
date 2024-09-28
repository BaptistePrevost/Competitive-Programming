/*
    Problem : https://codeforces.com/contest/2005/C
    Author : Baptiste Prévost
    Subjects : dp

    Idea : A fundamental idea is to consider each contribution of a letter to narek score separately.
    When considering the next string, dp[i] holds the maximal score obtained to 
    this point while looking for the the i-th letter in narek, i.e. while completing
    narek up to the i-1-th character.
    Then, the firt occurence of the i-th character in the current string is always the
    best to consider. For each possible next letter to be found in the string, one can greedily 
    find the maximum contribution to the score in the current string, and the next letter to look for.

    After the last string, the maximum score is either 0, or max(dp[i] - 2*i), since unfinished words
    don't contribute to the score.

    Complexity : 5nm
*/

#include <bits/stdc++.h>
#include <vector>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    int t;
    cin >> t;

    int n, m;
    int dp[2][5];
    string narek = "narek";
    while(t--) {
        cin >> n >> m;
        vector<string> s(n);
        for(int i=0; i<n; i++) cin >> s[i];

        dp[0][0] = 0;
        dp[0][1] = INT_MIN;
        dp[0][2] = INT_MIN;
        dp[0][3] = INT_MIN;
        dp[0][4] = INT_MIN;
        
        for(int i=0; i<n; i++) {
            for(int k=0; k<5; k++) dp[1][k] = dp[0][k];

            for(int k=0; k<5; k++) {
                if(dp[0][k] == INT_MIN) continue;
                int localScore = 0, lookingFor = k;
                for(int j=0; j<m; j++) {
                    int pos = narek.find(s[i][j]);
                    if(pos == -1) continue;
                    if(pos == lookingFor) {
                        lookingFor = (lookingFor + 1) % 5;
                        localScore++;
                    } else localScore--;
                }
                dp[1][lookingFor] = max(dp[1][lookingFor], dp[0][k]+localScore);
            }
            
            for(int k=0; k<5; k++) dp[0][k] = dp[1][k];
        }

        int ans = 0;
        for(int k=0; k<5; k++) if(dp[0][k] > INT_MIN) ans = max(ans, dp[0][k] - 2*k);

        cout << ans << endl;
    }
}
