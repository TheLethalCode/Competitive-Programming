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
#define MAXC 1000005
// %

int n, m, a, b, t, q, ok, cnt;
lli k, r, x, y, z, ans;
vector< int > v[MAXC];

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    FOR(i, n){
        cin >> a;
        if(v[a].empty()){
            v[a].pb(0);
        }
        v[a].pb(i+1);
    }
    lli val = 0;
    FOR(i, MAXC){
        if(v[i].size()){
            v[i].pb(n+1);
            lli cur = 1LL*n*n;
            for(int j=1;j<v[i].size();j++){
                int dis = v[i][j] - v[i][j-1] - 1;
                cur -= 1LL*dis*dis;
            }
            val += cur;
        }
    }
    double ans = val;
    ans /= 1LL*n*n;
    cout << fixed << setprecision(6) << ans <<'\n';
}