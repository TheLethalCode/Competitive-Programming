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
pair< int, int > S1, S2;

bool can(lli ans){
    lli full = abs(S2.se-S1.se) + abs(S1.fi-S2.fi), fI = max(S2.se, S1.se) - min(S1.fi, S2.fi);
    lli inter = max(min(S2.se, S1.se) - max(S1.fi, S2.fi), 0);
    for(int i=0;i<n;i++){
        if(full*i > ans){
            break;
        }
        lli cur = fI*i + inter*(n-i), rem = ans-full*i;
        lli l1 = S1.fi, l2 = S2.fi, r1 = S1.se, r2 = S2.se;
        if(l2 > r1){
            if(rem < l2 - r1){
                if(cur >= k){
                    return true;
                }
                continue;
            }
            rem -= l2-r1;
            l2 = r1;
        }
        lli cover = min(abs(l2-l1) + abs(r2-r1), rem);
        rem -= cover, cur += cover;
        cur += rem/2;
        if(cur >= k){
            return true;
        } 
    }
    return false;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        cin >> S1.fi >> S1.se;
        cin >> S2.fi >> S2.se;
        if(S1 > S2){
            swap(S1, S2);
        }
        lli ans = (1LL<<33) - 1;
        for(int i = 32;i>=0;i--){
            if(can(ans-(1LL<<i))){
                ans -= 1LL<<i;
            }
        }
        cout << ans << '\n';
    }
}