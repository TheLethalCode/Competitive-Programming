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

int n, m, a, b, c, t, ok, V[MAXC];
lli k, r, x, y, z;

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        FOR(i, n){
            cin >> V[i];
        }
        string ans(100, 'a');
        cout << ans << '\n';
        FOR(i, n){
            ans[V[i]]++;
            if(ans[V[i]] > 'z'){
                ans[V[i]] -= 26;
            }
            cout << ans << '\n';
        }
    }
}