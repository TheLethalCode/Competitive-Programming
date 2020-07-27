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
#define sz(a) (int)(a.size())
#define MAXC 200005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %

typedef pair< lli, pair< int, int > > path;
set< path, greater< path > > ans;

vector< pair< int, int> > ed[MAXC];
int n, m, k;

void solve(int u){
    set< int > vis;
    set< pair< lli, int> > track;
    track.insert({0, u});
    while(!track.empty()){
        pair< lli, int > cur = *track.begin();
        track.erase(track.begin());
        if(vis.count(cur.se)){
            continue;
        }
        vis.insert(cur.se);
        if(cur.se != u){
            ans.insert({cur.fi, {min(cur.se, u), max(cur.se, u)}});
            if(ans.size() > k){
                ans.erase(ans.begin());
            }
        }
        FORR(v, ed[cur.se]){
            track.insert({v.se+cur.fi, v.fi});
        }
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    vector< pair< int, pair<int, int > > > v;
    FOR(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        v.pb(c, make_pair(a, b));
    }
    sort(v.begin(), v.end());
    FOR(i, min(k, m)){
        ed[v[i].se.fi].pb(v[i].se.se, v[i].fi);
        ed[v[i].se.se].pb(v[i].se.fi, v[i].fi);
    }
    FOR(i, n){
        if(ed[i+1].size()){
            solve(i+1);
        }
    }
    cout << ans.begin()->fi << "\n";
}