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
int n, t, cnt, L[MAXC], R[MAXC];
struct event{
    int x, c, t, i;
    event(int _x, int _c, int _t, int _i) : x(_x), c(_c), t(_t), i(_i) {}
    bool operator<(const event &q) const{
        return make_pair(x, t) < make_pair(q.x, q.t);
    }
};

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector< event > E;
    cin >> n;
    FOR(i, n){
        cin >> L[i] >> R[i] >> t;
        E.pb(L[i], t-1, 0, i);
        E.pb(R[i], t-1, 1, i);
    }
    sort(E.begin(), E.end());
    set< pair< int, int > > S[2];
    FORR(eve, E){
        if(!eve.t){
            S[eve.c].insert({R[eve.i], eve.i});
        }
        else if(S[eve.c].count({R[eve.i], eve.i})){
            if(!S[!eve.c].empty()){
                cnt++;
                S[!eve.c].erase(S[!eve.c].begin());
            }
            S[eve.c].erase({R[eve.i], eve.i});
        }
    }
    cout << n - cnt << '\n';   
}