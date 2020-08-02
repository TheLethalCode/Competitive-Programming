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
#define MAXC 2005
// %
typedef double ftype; // Change the function type accordingly
int n, L[MAXC], R[MAXC], Y[MAXC];
double ans = 1e18;

struct event{
    double x;
    int t;
    event(double _x, int _t): x(_x), t(_t) {};
    bool operator<(const event& q) const{
        return make_pair(x, q.t) < make_pair(q.x, t);
    }
};

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
	const ftype inf = 1/.0;
	ftype div(ftype a, ftype b) {
		return a / b; 
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

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    CHT left, right;
    FOR(i, n){
        cin >> L[i] >> R[i] >> Y[i];
        left.add_line(-Y[i], -L[i]);
        right.add_line(Y[i], R[i]);
    }
    vector< event > events;
    FOR(i, n){
        FOR(j, i){
            if(Y[i] != Y[j]){
                int x = i, y = j;
                if(Y[x] < Y[y]){
                    swap(x, y);
                }
                events.pb((double) (L[y] - R[x]) / (Y[x] - Y[y]) , 0);
                events.pb((double) (R[y] - L[x]) / (Y[x] - Y[y]) , 1);
            }
        }
    }
    int cnt = 0;
    sort(events.begin(), events.end());
    FORR(eve, events){
        if(eve.t){
            cnt--;
            if(!cnt){
                ans = min(ans, right.query(eve.x) + left.query(eve.x));
            }
        }
        else{
            if(!cnt){
                ans = min(ans, right.query(eve.x) + left.query(eve.x));
            }
            cnt++;
        }
    }
    if(events.empty()){
        ans = min(ans, right.query(0) + left.query(0));
    }
    cout << fixed << setprecision(8) << ans << '\n';
}