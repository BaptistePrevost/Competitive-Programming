#include <bits/stdc++.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const ll MAXN = 200009;

typedef struct {
    ll w;
    ll h;

    ll minDim() const {return min(h, w);}
    ll maxDim() const {return max(h, w);}

    ll cost(ll k) {
        if(maxDim()-minDim()+1 >= k) return k*minDim();
        ll ans = (maxDim()-minDim()+1)*minDim();
        k -= maxDim()-minDim()+1;
        ll dim = minDim()-1;
        while(k > 0) {
            ans += dim;
            k--;
            if(k <= 0) break;
            ans += dim;
            k--;
            if(k <= 0) break;
            dim--;
        }
        return ans;
    }

} Rectangle;

bool comp(Rectangle &r1, Rectangle &r2) {
    return (r1.h*r1.w)/(r1.h+r1.w) < (r2.h*r2.w)/(r2.h+r2.w);
}

int main() {
    ll t;
    cin >> t;
    
    ll n, k;
    ll a, b;
    ll ans;
    vector<Rectangle> r;
    
    while(t--) {
        cin >> n >> k;

        ans = 0;
        r.clear();
        for(int i=0; i<n; i++) {
            cin >> a >> b;
            r.push_back({a,b});
        }

        sort(r.begin(), r.end(), comp);

        // Hack to output missed testcase 3
        // if(t == 100-57 && !(r[0].w == 2 && r[0].h == 10)) {
        //     for(int i=0; i<n; i++) {
        //         cout << r[i].w << " " << r[i].h << endl;
        //     }
        // }

        auto it = r.begin();
        while(it != r.end()) {
            if(k - (it->w+it->h) < 0) break;
            k -= it->w + it->h;
            ans += it->w * it->h;
            it++;
        }


        if(k>0 && it == r.end()) ans = -1;
        else if(k>0) {
            ll minCost = it->cost(k);
            it++;       
            while(it != r.end()) {
                if(it->h + it->w - 1 >= k) {
                    minCost = min(minCost, it->cost(k));
                }  
                it++;
            }
            ans += minCost;
        }
        cout << ans << endl;
    }
}