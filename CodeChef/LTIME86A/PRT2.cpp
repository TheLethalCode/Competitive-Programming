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
#define MAXC 300005
// %

int n, m, i, j, t, q, ok, cnt, ans;
lli k, r, x, y, z, V[MAXC];
string s, c;
vector< int > to[MAXC];

int dfs(int u, int p=-1){
    int dis = MAXC + 1;
    FORR(v, to[u]){
        if(v != p){
            int res = dfs(v, u);
            ans = min(ans, dis + res + 1);
            dis = min(dis, res);
        }
    }
    if(dis != MAXC+1 && to[u].size()==1){
        ans = min(ans, dis+1);
    }
    return (dis==MAXC+1?1:dis+1);
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        lli ar[n]; 
        FOR(i, n){
            cin >> ar[i];
            to[i+1].clear();
        }
        sort(ar, ar+n);
        reverse(ar, ar+n);
        FOR(i, n-1){
            cin >> x >> y;
            to[x].pb(y);
            to[y].pb(x);
        }
        ans = MAXC+1;
        dfs(1);
        FOR(i, n){
            V[i+1] = V[i] + ar[i];
        }
        z = k/(2*ans)*2*V[ans];
        k %= 2*ans;
        if(k > 2){
            z += 2*V[k/2] + (k&1)*ar[k/2];
        }
        else{
            z += (k>=2?ar[1]:0) + (k>=1?ar[0]:0); 
        }
        cout << z << '\n';
    }  
}