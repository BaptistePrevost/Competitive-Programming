/*
    Problem : 
    Author : Baptiste Prévost
    Subjects :

    Idea :

    Complexity :
*/

#include <bits/stdc++.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)


ld EPS = 1e-12;

struct Point {
    ld x;
    ld y;

    ld squareDistTo(const Point &p) const {
        return (p.x-x)*(p.x-x) + (p.y-y)*(p.y-y);
    }

    ld distTo(const Point &p) const {
        return sqrtl(squareDistTo(p));
    }

    bool isInf = false;
};

struct Side {
    Point p1;
    Point p2;

    Side(Point p1, Point p2): p1(p1), p2(p2) {}

    ld squareLength() {
        return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
    }

    ld length() {
        return sqrtl(squareLength());
    }

    Point intersection(const Side &s) {
        if(p1.x == p2.x) {
            if(s.p1.x == s.p2.x) return {0,0,true};
            return {p1.x, (s.p2.y - s.p1.y)/(s.p2.x - s.p1.x) * (p1.x - s.p2.x) + s.p2.y};
        } else {
            if(s.p1.x == s.p2.x) return {s.p1.x, (p2.y - p1.y)/(p2.x - p1.x) * (s.p1.x - p2.x) + p2.y};
            ld a = (p2.y - p1.y)/(p2.x - p1.x);
            ld sa = (s.p2.y - s.p1.y)/(s.p2.x - s.p1.x);
            if(abs(sa-a) < EPS) return {0,0,true};
            ld x = (a*p2.x - sa*s.p2.x + s.p2.y - p2.y) / (a-sa);
            ld y = a*(x-p2.x)+p2.y;
            return {x,y};
        }
    }

    bool contains(const Point &p) const {
        ld leftX = min(p1.x, p2.x);
        ld rightX = max(p1.x, p2.x);
        ld botY = min(p1.y, p2.y);
        ld topY = max(p1.y, p2.y);

        if(leftX - EPS > p.x || rightX + EPS < p.x 
            || botY - EPS > p.y || topY + EPS < p.y) return false;
        
        if(p1.x == p2.x) return (p.x == p1.x);
        ld y = (p2.y - p1.y) / (p2.x - p1.x) * (p.x - p1.x) + p1.y;
        return (abs(y - p.y) <= EPS);
    }

    const Point left() const {
        if(p1.x < p2.x) return p1;
        return p2;
    }

    const Point right() const {
        if(p1.x >= p2.x) return p1;
        return p2;
    }

    const Point bot() const {
        if(p1.y < p2.y) return p1;
        return p2;
    }

    const Point top() const {
        if(p1.y >= p2.y) return p1;
        return p2;
    }
};


vector<Point> pts;
vector<Side> sds;

int countIntersectionsWithSides(Side ray) {
    int nbInter = 0;
    for(const Side &s : sds) {
        Point inter = ray.intersection(s);
        if(inter.isInf) continue;
        nbInter += (ray.contains(inter) && s.contains(inter));
    }
    return nbInter;
}

int countIntersectionsWithVertices(Side ray) {
    int nbInter = 0;
    forn(i,0,pts.size()-1) {
        const Point &p = pts[i];
        if(p.x == ray.p1.x && p.y == ray.p1.y) continue;
        if(p.x == ray.p2.x && p.y == ray.p2.y) continue;
        if(ray.contains(p)) {
            // the point p is really crossed by the segment [p1,p2] if [p,p1] or
            // [p,p2] forms
            const Point &pp = pts[(i-1)%pts.size()];
            const Point &np = pts[(i+1)%pts.size()];

            ld pdot = (ray.p1.x-p.x)*(pp.x - p.x) + (ray.p1.y-p.y)*(pp.y - p.y);
            ld pdet = (ray.p1.x-p.x)*(pp.y - p.y) + (ray.p1.y-p.y)*(pp.x - p.x);
            ld pangle = atan2(pdet, pdot);

            ld ndot = (ray.p1.x-p.x)*(np.x - p.x) + (ray.p1.y-p.y)*(np.y - p.y);
            ld ndet = (ray.p1.x-p.x)*(np.y - p.y) + (ray.p1.y-p.y)*(np.x - p.x);
            ld nangle = atan2(ndet, ndot);

            if((pangle >= 0 && nangle >= 0) || (pangle <= 0 && nangle <= 0)) {
                nbInter++;
                continue;
            }

            pdot = (ray.p2.x-p.x)*(pp.x - p.x) + (ray.p2.y-p.y)*(pp.y - p.y);
            pdet = (ray.p2.x-p.x)*(pp.y - p.y) + (ray.p2.y-p.y)*(pp.x - p.x);
            pangle = atan2(pdet, pdot);

            ndot = (ray.p2.x-p.x)*(np.x - p.x) + (ray.p2.y-p.y)*(np.y - p.y);
            ndet = (ray.p2.x-p.x)*(np.y - p.y) + (ray.p2.y-p.y)*(np.x - p.x);
            nangle = atan2(ndet, ndot);

            if((pangle >= 0 && nangle <= 0) || (pangle <= 0 && nangle >= 0)) nbInter++;
        };
    }

    return nbInter;
}

ld solve(Point A, Point B, Point U) {
    // Here, we chose A and B such that there isn't any side including inside
    // (crossing is allowed ofc)
    if(A.x > B.x) swap(A,B);
    Side ray = Side(A,U);
    bool inside = ((countIntersectionsWithSides(ray) + countIntersectionsWithVertices(ray))%2 == 1);

    Side AB(A, B);
    ld ret = 0;
    vector<Point> crossings;
    crossings.push_back(A);
    crossings.push_back(B);
    for(const Side &s : sds) {
        Point inter = AB.intersection(s);
        if(inter.isInf) continue;
        if(AB.contains(inter) && s.contains(inter)) crossings.push_back(inter);
    }
    for(const Point &p : pts) {
        if(AB.contains(p)) crossings.push_back(p);
    }

    sort(crossings.begin(),crossings.end(),[&](Point &p1, Point &p2) {return A.squareDistTo(p1) < A.squareDistTo(p2);});

    forn(j,0,crossings.size()-2) {
        if(inside) ret += crossings[j].distTo(crossings[j+1]);
        inside = !inside;
    }

    return ret;
}

int main() {
    srand(42);
    ll n, m;
    cin >> n >> m;
    
    Point U = {LLONG_MIN, LLONG_MIN};
    pts.resize(n);
    forn(i,0,n-1) {
        cin >> pts[i].x >> pts[i].y;
        U.x = max(U.x, pts[i].x + 10);
        U.y = max(U.y, pts[i].y + 10);
    }

    forn(i,0,n-2) {
        sds.push_back(Side(pts[i], pts[i+1]));
    }
    sds.push_back(Side(pts[n-1], pts[0]));

    Point A, B;
    forn(i,1,m) {
        cin >> A.x >> A.y >> B.x >> B.y;
        if(A.x > B.x) swap(A, B);

        ld ans = 0;
        Side AB(A,B);
        if(A.x != B.x) {
            ld pente = (AB.p1.y - AB.p2.y) / (AB.p1.x - AB.p2.x);
            vector<pair<ld, ld>> ranges;
            for(const Side &s : sds) {
                if(!s.contains(A) && !AB.contains(s.left())) continue;
                if(s.p1.x == s.p2.x) continue;
                if(abs((s.p1.y - s.p2.y) / (s.p1.x - s.p2.x) - pente) <= EPS) {
                    ranges.push_back({max(s.left().x, A.x), min(s.right().x, B.x)});
                }
            }
            ranges.push_back({A.x, A.x});
            ranges.push_back({B.x, B.x});

            sort(ranges.begin(), ranges.end());
            ld rightMostX = A.x;
            Point lastRightMostPoint = A;
            for(const pair<ld, ld> &r : ranges) {
                if(r.first <= rightMostX) {
                    rightMostX = max(rightMostX, r.second);
                    if(rightMostX >= B.x) {
                        ans += lastRightMostPoint.distTo(B);
                        break;
                    }
                } else {
                    ld x = rightMostX + 10*EPS;
                    ld y = (x-B.x)*(B.y-A.y)/(B.x - A.x) + B.y;
                    Point rightMostPoint = {x, y};
                    ans += lastRightMostPoint.distTo(rightMostPoint);

                    lastRightMostPoint = {r.first, (r.first-B.x)*(B.y-A.y)/(B.x - A.x) + B.y};
                    rightMostX = r.second;
                    ans += solve(rightMostPoint, lastRightMostPoint, U);
                }
            }
        } else {
            vector<pair<ld, ld>> ranges;
            for(const Side &s : sds) {
                if(!s.contains(AB.bot()) && !AB.contains(s.bot())) continue;
                if(s.p1.x != s.p2.x) continue;
                ranges.push_back({max(s.bot().y, AB.bot().y), min(s.top().y, AB.top().y)});
            }
            ranges.push_back({A.y, A.y});
            ranges.push_back({B.y, B.y});

            sort(ranges.begin(), ranges.end());
            ld topMostY = AB.top().y;
            Point lastTopMostPoint = AB.bot();
            for(const pair<ld, ld> &r : ranges) {
                if(r.first <= topMostY) {
                    topMostY = max(topMostY, r.second);
                    if(topMostY >= AB.top().y) {
                        ans += lastTopMostPoint.distTo(AB.top());
                        break;
                    }
                } else {
                    Point topMostPoint = {A.x, topMostY + 10*EPS};
                    ans += lastTopMostPoint.distTo(topMostPoint);

                    lastTopMostPoint = {A.x, r.first};
                    topMostY = r.second;
                    ans += solve(topMostPoint, lastTopMostPoint, U);
                }
            }
        }

        cout << fixed << setprecision(8) << ans << endl;
    }

    return 0;
}
