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

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, cnt=1;
    lli ans = 1e18;
    cin>>n>>k;
    vector< int > v(n);
    vector< lli > pref(n+1);
    map< int, int > mp;
    FOR(i, n){
        cin>>v[i];
        mp[v[i]]++;
    } 
    sort(all(v));
    FOR(i, n){
        pref[i+1] = pref[i] + v[i]; 
    }
    FORR(el, mp){
        int bef = lower_bound(all(v), el.fi) - v.begin() - 1;
        int aft = upper_bound(all(v), el.fi) - v.begin();
        if(el.se >= k){
            cout<< 0 << "\n";
            return 0;
        }
        lli bef_ans = 1LL*(el.fi-1)*(bef+1) - pref[bef+1];
        lli aft_ans = (pref[n] - pref[aft]) - 1LL*(el.fi+1)*(n-aft);
        if(bef + 1 >= k-el.se){
            ans = min(ans, bef_ans + k - el.se);
        }
        if(n - aft >= k-el.se){
            ans = min(ans, aft_ans + k - el.se);
        }
        ans = min(ans, bef_ans + aft_ans + k-el.se);
    }
    cout<< ans << "\n";
}