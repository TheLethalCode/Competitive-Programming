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
#define MAXC 200005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %

int depth[MAXC], below[MAXC];
vector < int >  v[MAXC];

int dfs(int u, int p=-1, int h=0){
    depth[u] = h;
    below[u] = 0;
    FORR(v, v[u]){
        if(v != p){
            below[u] += dfs(v, u, h+1);
        }
    }
    return below[u]+1;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, cnt=0;
    cin >> n >> k;
    FOR(i, n-1){
        int a, b;
        cin >> a >> b;
        v[a].pb(b);
        v[b].pb(a);
    }
    dfs(1);
    map< int, int , greater<int> > mp;
    for(int i=1;i<=n;i++){
        mp[depth[i] - below[i]]++;
    }
    lli ans = 0;
    FORR(el, mp){
        int x = min(el.se, k-cnt);
        ans += 1LL * el.fi * x;
        cnt += x;
        if(cnt >= k){
            break;
        }
    }
    cout << ans << "\n";
}