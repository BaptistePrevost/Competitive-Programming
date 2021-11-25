// Freely inspired from https://github.com/DrSwad/CompetitiveProgramming/blob/master/SPOJ/SPOJ%20RAIN1

#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

pair<int, int> leftEnd[40001];
pair<int, int> rightEnd[40001];
vector<pair<int, int> > abscisses; //abscisse, index
vector<int> dropX[40001];
int water[40001];
int bests[40001];

bool comp2(int ind1, int ind2, int atX) { //Compares two candidates for a given X
    long long int a1 = (long long int)((float)(rightEnd[ind1].second - leftEnd[ind1].second)/(float)(rightEnd[ind1].first - leftEnd[ind1].first));
    long long int a2 = (long long int)((float)(rightEnd[ind2].second - leftEnd[ind2].second)/(float)(rightEnd[ind2].first - leftEnd[ind2].first));
    int b1 = leftEnd[ind1].second - a1 * leftEnd[ind1].first;
    int b2 = leftEnd[ind2].second - a1 * leftEnd[ind2].first;
    int y1 = a1*atX + b1;
    int y2 = a2*atX + b2;

    return y1 > y2;
}


int main() {
    int t;
    scanf("%i", &t);
    while(t--) {
        int n;
        scanf("%i", &n);
        // abscisses.clear();

        for(int i = 0; i < n; i++) {
            scanf("%i %i %i %i", &leftEnd[i].first, &leftEnd[i].second, &rightEnd[i].first, &rightEnd[i].second);
            abscisses.push_back(make_pair(leftEnd[i].first, i));
            abscisses.push_back(make_pair(rightEnd[i].first, i));
            dropX[leftEnd[i].second < rightEnd[i].second ? leftEnd[i].first : rightEnd[i].first].push_back(i);
        }
        leftEnd[n].first = -1; leftEnd[n].second = -1; rightEnd[n].first = 1000001; rightEnd[n].second = -1;
        abscisses.push_back(make_pair(-1, n));
        abscisses.push_back(make_pair(1000001, n));
        sort(abscisses.begin(), abscisses.end());
        abscisses.resize(unique(abscisses.begin(), abscisses.end()) - abscisses.begin()); // ???

        // for(int i = 0; i < 2*n + 2; i++) {
        //     printf("%i %i\n", leftEnd[abscisses[i].second].first, leftEnd[abscisses[i].second].second);
        // }

        vector<int> currents;
        for(int i = 0; i < 2*n + 1; ) {
            int j = i;
            int atX = abscisses[i].first;
            //New currents
            // printf("New currents\n");
            while(j < 2*n + 1 && abscisses[j].first == atX) {
                if(leftEnd[abscisses[j].second].first == atX) {
                    int insert = 0;
                    while(insert < currents.size() && comp2(abscisses[j].second, currents[insert], atX)) insert++;
                    currents.insert(currents.begin() + insert, abscisses[j].second);
                    // printf("\t new : %i %i \n", leftEnd[abscisses[j].second].first, leftEnd[abscisses[j].second].second);
                }
                j++;   
            }
            //Dropping
            // printf("Dropping\n");
            for(int k : dropX[atX]) {
                int index = find(currents.begin(), currents.end(), k) - currents.begin();
				bests[k] = currents[index - 1];
                // printf("\t%i %i drops on %i %i\n", leftEnd[k].first, leftEnd[k].second, leftEnd[currents[index - 1]].first, leftEnd[currents[index - 1]].second);
            }
            //Clean currents
            // printf("Clean currents\n");
            for (int k = i; k < j; k++) {
				int ind = abscisses[k].second;
				if (rightEnd[ind].first == atX) {
					currents.erase(find(currents.begin(), currents.end(), ind));
				}
			}

            //Sky water
			if (j < abscisses.size()) {
                water[currents.back()] += abscisses[j].first - abscisses[i].first;
                // printf("Pouring %i to %i %i (%i)\n", abscisses[j].first - abscisses[i].first, leftEnd[currents.back()].first, leftEnd[currents.back()].second, water[currents.back()]);
            }

            i = j;
        }

        // Finally do a topological sort
		vector<int> indeg(n + 1, 0);
        for (int i = 0; i <= n; i++) indeg[bests[i]]++;
        queue<int> q;
        for (int i = 0; i <= n; i++) if (indeg[i] == 0) q.push(i);
        while (!q.empty()) {
			int at = q.front(), down = bests[at];
			water[down] += water[at];
			indeg[down]--;
			if (indeg[down] == 0 && down != 0) q.push(down);
			q.pop();
		}

        
        for(int i = 0; i < n; i++) printf("%i\n", water[i]);

        // // reset everything
		fill(water, water + n + 1, 0);
		for (int i = 0; i < n; i++) dropX[abscisses[i].first].clear();
        
    }
    return 0;
}