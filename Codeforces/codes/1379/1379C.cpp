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

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector< pair< pair< int, int > , int > > ar(m), cp; 
        FOR(i, m){
            cin >> ar[i].fi.se >> ar[i].fi.fi;
            ar[i].se = i;
        }

        cp = ar;
        vector< int > ord(m);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j){
            return ar[i].fi.se > ar[j].fi.se;
        });
        sort(ar.rbegin(), ar.rend());
        
        lli ans = 0, sum = 0;
        int cur = 0, mark[m] = {};
        for(int i = 0; i <= min(m, n); i++){
            int gr = i<m?cp[ord[i]].fi.se:-1;
            for(;cur<m && ar[cur].fi.fi > gr; cur++){
                if(mark[ar[cur].se]){
                    ans = max(ans, sum + 1LL*(n-i)*ar[cur].fi.fi);
                }
                else if(i < n){
                    ans = max(ans, sum + 1LL*(n-i-1)*ar[cur].fi.fi + ar[cur].fi.se);
                }
            }
            if(i < m && i < n){
                mark[ord[i]] = 1;
                sum += cp[ord[i]].fi.se;
                ans = max(ans, sum);
            }
        }
        cout << ans << '\n';
    }
}