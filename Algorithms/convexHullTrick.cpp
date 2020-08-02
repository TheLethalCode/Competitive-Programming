#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mod 1000000007
#define lli long long
#define fi first
#define se second
#define pb emplace_back
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define MAXC 200005
// %

// Convex Hull Trick for finding the maximum value 
// among a set of linear functions of the form y = mx + c.
// To find the minimum, use the line as y = -mx-c;
// 
// Test :- Solves CF - 1388E 
// Insertion time :- O(logN) (amortized)
// Query time :- O(logN)

typedef lli ftype; // Change the function type accordingly

struct Line{
	mutable ftype m, c, x;
	bool operator<(const Line& q) const{ 
        return m < q.m; 
    }
	bool operator<(ftype q) const{ 
        return x < q; 
    }
};

struct CHT : multiset< Line, less<> > {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ftype inf = LLONG_MAX;
	ftype div(ftype a, ftype b) {
		return a / b - ((a ^ b) < 0 && a % b); 
    }
	bool isect(iterator a, iterator b){
		if(b == end()){ 
            a->x = inf; 
            return false; 
        }
		if(a->m == b->m){
            a->x = a->c > b->c ? inf : -inf;
        }
		else{
            a->x = div(b->c - a->c, a->m - b->m);
        }
		return a->x >= b->x;
	}
	void add_line(ftype m, ftype c){
		auto z = insert({m, c, 0}), y = z++, x = y;
		while(isect(y, z)){
            z = erase(z);
        }
		if(x != begin() && isect(--x, y)){
            isect(x, y = erase(y));
        }
		while((y = x) != begin() && (--x)->x >= y->x){
			isect(x, erase(y));
        }
	}
	ftype query(ftype x){
		assert(!empty());
		auto l = *lower_bound(x);
		return l.m * x + l.c;
	}
};