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
    int n;
    cin >> n;
    vector< lli > pref(2*n+1);
    lli ans = 0;
    FOR(i, n){
        cin >> ans;
        pref[i+1] = pref[i+n+1] = ans;
    }
    for(int i=3; i <= 2*n; i++){
        pref[i] += pref[i-2]; 
        if(i > n){
            ans = max(ans, pref[i] - pref[i-n-1]);
        }
    }
    cout << ans << '\n';
}