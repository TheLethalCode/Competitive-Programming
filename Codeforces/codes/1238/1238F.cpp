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
#define MAXC 300005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %

vector< int > ed[MAXC];
int ans = 1;

int dfs(int u, int p){
    vector< int > temp;
    FORR(v, ed[u]){
        if(v != p){
            temp.pb(dfs(v, u));
        }
    }
    int m = sz(temp), rootAns, notRoot=1;
    if(m){
        sort(temp.rbegin(), temp.rend());
        notRoot = temp[0] + m;
        if(m > 1){
            rootAns = temp[0] + temp[1] + m - (p==-1);
            ans = max(ans, rootAns);
        }
        ans = max(ans, notRoot);
    }
    return notRoot;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        ans = 1;
        cin >> n;
        FOR(i, n){
            ed[i+1].clear();
        }
        FOR(i, n-1){
            int a, b;
            cin >> a >> b;
            ed[a].pb(b);
            ed[b].pb(a);
        }
        dfs(1, -1);
        cout << ans << "\n";
    }
}