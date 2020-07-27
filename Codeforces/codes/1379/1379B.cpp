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
        lli l, r, m;
        cin >> l >> r >> m;
        for(int i = l; i <= r; i++){
            int rem = m%i;
            if(rem <= r-l && m/i){
                cout << i << " " << l + rem << " " << l <<"\n";
                break;
            }
            else if(i-rem <= r-l){
                cout << i << " " << l << " " << l + i - rem <<"\n";
                break;
            }
        }
    }
}