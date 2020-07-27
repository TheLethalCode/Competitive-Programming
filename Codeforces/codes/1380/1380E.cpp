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

int par[MAXC], tow[MAXC];

int f(int x){
    if(tow[x] == x){
        return x;
    }
    return tow[x] = f(tow[x]);
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, cnt = 0, x;
    cin >> n >> m;
    vector< int > pos[m+1], v(n);
    FOR(i, m){
        tow[i+1] = i+1;
    }
    FOR(i, n){
        cin >> x;
        par[i+1] = x;
        pos[x].pb(i+1);
        if(i && par[i] == par[i+1]){
            cnt++;
        }
    }
    cout << n - 1 - cnt << "\n";
    FOR(i, m-1){
        int x, y;
        cin >> x >> y;
        x = f(x), y = f(y);
        if(sz(pos[x]) > sz(pos[y])){
            swap(x, y);
        }
        FORR(el, pos[x]){
            cnt += (f(par[el-1]) == y) + (f(par[el+1]) == y);
            pos[y].pb(el);
        }
        tow[x] = y;
        cout << n - 1 - cnt << "\n";
    }
}