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
#define ordered_set tree< pair<int, int>, null_type, less< pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update>
#define MAXC 100005
// %
int n, k, X[MAXC], R[MAXC], Q[MAXC];
lli ans;

struct event{
    int x, t, i;
    event(int _x, int _t, int _i) : x(_x), t(_t), i(_i) {}
    bool operator< (const event& q) const {
        return make_pair(x, t) < make_pair(q.x, q.t);
    }
};

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector< event > E;
    cin >> n >> k;
    FOR(i, n){
        cin >> X[i] >> R[i] >> Q[i];
        E.pb(X[i] - R[i], 0, i);
        E.pb(X[i], 1, i);
        E.pb(X[i] + R[i], 2, i);
    }
    sort(E.begin(), E.end());
    map< int, ordered_set > M;
    FORR(e, E){
        if(e.t == 0){
            M[Q[e.i]].insert({X[e.i], e.i});
        }
        else if(e.t == 2){
            M[Q[e.i]].erase(M[Q[e.i]].find({X[e.i], e.i}));
        }
        else{
            for(int i = -k + Q[e.i]; i <= k + Q[e.i]; i++){
                if(M.count(i)){
                    ans += M[i].order_of_key(make_pair(X[e.i]+R[e.i]+1, -1)) - M[i].order_of_key(make_pair(X[e.i]-R[e.i], -1));
                }
            }
            ans--;
        }
    }
    cout << ans/2 << '\n'; 
}