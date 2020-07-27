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
#define MAXC mod-7
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, i=1;
    vector< int > ans;
    cin>>n>>m;
    lli tot = 0;
    while(i<=n){
        if(tot + (i-1)/2 > m){
            break;
        }
        tot += (i-1)/2;
        ans.pb(i);
        i++;
    }
    if(tot < m && i>n){
        cout << -1 << "\n";
        return 0;
    }
    if(i <= n){
        if(tot < m){
            int j = i-1;
            while(tot + (i-j)/2 < m) j--;
            ans.pb(i-1+j);
            i++;
        }
        while(i<=n){
            ans.pb(MAXC-(n-i)*20000);
            i++;
        }
    }
    FORR(x, ans){
        cout << x << " ";
    }
    cout << "\n" ;
}