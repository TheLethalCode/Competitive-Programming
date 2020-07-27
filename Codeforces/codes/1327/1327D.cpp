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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %
#define MAXC 200005
int n, c[MAXC];

int solve(vector<int> &cyc){
    int r = sz(cyc);
    for(int i=1;i<=r;i++){
        if( r % i == 0 ){
            FOR(j, i){
                int fl = 1;
                for(int x = j;x < r && fl;x+=i){
                    fl &= (c[cyc[x]]==c[cyc[j]]);
                }
                if(fl){
                    return i;
                }
            }
        }
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int p[n], ans = 1e6;
        FOR(i, n) {
            cin>>p[i];
            p[i]--;
        }
        FOR(i, n) {
            cin>>c[i];
        }
        vector< int > vis(n, -1);
        FOR(i, n){
            if(vis[i]==-1){
                int x = i;
                vector< int > temp;
                while(vis[x]==-1){
                    vis[x] = 1;
                    temp.pb(x);
                    x = p[x];
                }
                ans = min(ans, solve(temp));
            }
        }
        cout<< ans << "\n";
    }
}