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
#define MAXC 10000001
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %

int pos[MAXC], fact[MAXC], n, x, i1, i2;
lli ans = 1LL*mod*mod;

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    FOR(i, n){
        cin >> x;
        if(pos[x] && x < ans){
            ans = x;
            i1 = pos[x], i2 = i+1;
        }
        pos[x] = i+1;
    }
    for(int i=1;i<MAXC && i<ans;i++){
        for(int j=i;j<MAXC && j<ans;j+=i){
            if(pos[j] && fact[i]){
                lli val = 1LL*j*fact[i]/i;
                if(ans > val){
                    ans = val;
                    i1 = pos[j];
                    i2 = pos[fact[i]];
                }
                break;
            }
            if(pos[j]){
                fact[i] = j;
            }
        }
    }
    cout << min(i1, i2) << ' ' << max(i1, i2) << '\n';
}