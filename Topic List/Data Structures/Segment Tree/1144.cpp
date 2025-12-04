/*
    Problem : https://cses.fi/problemset/task/1144/
    Author : Baptiste Prévost
    Subjects : segment tree, coordinate compression

    Idea :

    Complexity :
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;


typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vll;

/* Supports
    insert,
    erase,
    order_of_key (returns an iterator to the k-th largest element counting from zero),
    find_by_order (number of items in a set that are strictly smaller than our item)
*/  
template<class T> using order_statistic_tree =
__gnu_pbds::tree<
    T, // Key type
    __gnu_pbds::null_type, // Mapped-policy
    std::less<T>, // Key comparison functor
    __gnu_pbds::rb_tree_tag, // Specifies which underlying data structure to use
    __gnu_pbds::tree_order_statistics_node_update // A policy for updating node invariants
>;

#define forn(i,j,k) for(ll i=(j); i<=(k); i++)
#define rofn(i,j,k) for(ll i=(j); i>=(k); i--)
#define forv(b,a) for(auto &b : a)
#define yon(t) cout << (t ? "YES" : "NO") << endl;
#define out(x) cout << x << " ";
#define outln(x) cout << x << endl;
#define in(x) cin >> x;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    fastIO();
    ll n, q;
    in(n) in(q)
    vector<ll> v(n+1);
    order_statistic_tree<pair<ll, ll>> ost;
    forn(i,1,n) {
        in(v[i]);
        ost.insert({v[i], i});
    }

    char c; ll a, b;
    forn(i,1,q) {
        in(c) in(a) in(b)
        if(c=='?') {
            outln(ost.order_of_key({b, 1e15}) - ost.order_of_key({a-1, 1e15}));
        } else {
            ost.erase({v[a], a});
            v[a] = b;
            ost.insert({v[a], a});
        }
    }

    return 0;
}
