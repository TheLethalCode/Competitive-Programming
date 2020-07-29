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

int n, m, a, b, t, q, ok, cnt;
lli k, r, x, y, z, ans;

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k >> z;
        vector< int > v(n), pref(n+1), M(n+1);
        FOR(i, n){
            cin >> v[i];
            pref[i+1] = pref[i] + v[i];
            if(i>=1){
                M[i+1] = max(M[i], v[i]+v[i-1]);
            }
        }
        int ans = pref[k+1];
        for(int i=1;i<=z;i++){
            if(k < 2*i){
                break;
            }
            int end = 1 + k - 2*i;
            ans = max(ans, pref[end] + i*M[end]);
            ans = max(ans, pref[end+1] + (i-1)*M[end+1] + v[end-1]);
        }
        cout << ans << '\n';
    }
}