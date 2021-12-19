/*
    Author : Baptiste Prévost

    Idea : 
        - Find the extreme points on each side
        - compare all possible triangles
        - WA, no idea why
*/

#include <iostream>
using namespace std;

struct p{
    int x,y;
};

int main() {
    int t, w, h, k, x, y;
    struct p p1a, p1b, p2a, p2b, p3a, p3b, p4a, p4b;
    cin >> t;
    while(t--) {
        cin >> w >> h;

        p1a.x = w; p1a.y = 0;
        p1b.x = 0; p1b.y = 0;
        p2a.x = w; p2a.y = h;
        p2b.x = 0; p2b.y = h;
        p3a.y = h; p3a.x = 0;
        p3b.y = 0; p3b.x = 0;
        p4a.y = h; p4a.x = w;
        p4b.y = 0; p4b.x = w;

        cin >> k;
        for(int i = 0; i < k; i++) {
            cin >> x;
            if(x < p1a.x) {
                p1a.x = x;
            }
            if(x > p1b.x) {
                p1b.x = x;
            }
        }

        cin >> k;
        for(int i = 0; i < k; i++) {
            cin >> x;
            if(x < p2a.x) {
                p2a.x = x;
            }
            if(x > p2b.x) {
                p2b.x = x;
            }
        }

        cin >> k;
        for(int i = 0; i < k; i++) {
            cin >> y;
            if(y < p3a.y) {
                p3a.y = y;
            }
            if(y > p3b.y) {
                p3b.y = y;
            }
        }

        cin >> k;
        for(int i = 0; i < k; i++) {
            cin >> y;
            if(y < p4a.y) {
                p4a.y = y;
            }
            if(y > p4b.y) {
                p4b.y = y;
            }
        }


        cout << max(max(p1b.x-p1a.x, p2b.x - p2a.x)*h, max(p3b.y-p3a.y, p4b.y - p4a.y)*w) << endl;
    }
    return 0;
}