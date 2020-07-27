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
#define all(v) v.begin(), v.end()
#define sz(a) (int)(a.size())
#define MAXC 500005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %
int n, s[MAXC];
vector < int >  ed[MAXC];
pair< int, int > ans[MAXC];
int dfs(int u, int p){
    s[u] = 1;
    FORR(v, ed[u]){
        if(v != p){
            s[u] += dfs(v, u);
        }
    }
    return s[u];
}
void assgn(int u, int p, int st, int en){
    ans[u] = make_pair(st, en);
    st = en-1;
    FORR(v, ed[u]){
        if(v != p){
            assgn(v, u, st, en+sz(ed[v]));
            en += 2*s[v] - 1;
            st--;
        }
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    FOR(i, n-1){
        int a, b;
        cin >> a >> b;
        ed[a].pb(b);
        ed[b].pb(a);
    }
    dfs(1, -1);
    assgn(1, -1, 1, 2+sz(ed[1]));
    FOR(i, n){
        cout << ans[i+1].fi << " " << ans[i+1].se << "\n";
    }
}