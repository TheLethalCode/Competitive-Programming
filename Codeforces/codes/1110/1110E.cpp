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

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, fl = 1;
    cin >> n;
    vector< int > c(n), t(n);
    map< int, int > mp;
    FOR(i, n){
        cin >> c[i];
        if(i > 0){
            mp[c[i]-c[i-1]]++;
        }
    }
    FOR(i, n){
        cin >> t[i];
        if(!i || i==n-1){
            if(t[i]!=c[i]){
                fl = 0;
            }
        }
        else{
            if(mp[t[i]-t[i-1]]){
                mp[t[i]-t[i-1]]--;
            }
            else{
                fl=0;
            }
        }
    }
    cout << (fl? "Yes": "No") << '\n';
}