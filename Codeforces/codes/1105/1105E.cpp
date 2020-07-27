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
int n, m, x, cnt = 0, ans;
lli nope[41], mask = 0;
string s;
vector< int > T;
map< lli, int > dp;
map< string, int > mp;

int solve(lli mask){
    if(dp.count(mask)){
        return dp[mask];
    }
    int b = __builtin_ctzll(mask);
    return dp[mask] = max(solve(mask-(1LL<<b)), 1+solve(mask&nope[b]));
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> x;
    fill_n(nope, m, (1LL<<m)-1);
    FOR(i, n-1){
        cin >> x;
        if(x==2){
            cin >> s;
            if(!mp.count(s)){
                mp[s] = cnt++;
            }
            T.pb(mp[s]);
        }
        if(x==1 || i==n-2){
            sort(T.begin(), T.end());
            int sz = unique(T.begin(), T.end()) - T.begin();
            FOR(i, sz){
                FOR(j, i){
                    if(nope[T[i]]>>T[j] & 1){
                        nope[T[i]] -= 1LL<<T[j];
                        nope[T[j]] -= 1LL<<T[i];
                    }
                }
            }
            T.clear();
        }
    }
    FOR(i, m){
        if(nope[i]==(1LL<<m)-1){
            ans++;
        }
        else{
            mask |= 1LL<<i;
            nope[i] -= 1LL<<i;
        }
    }
    dp[0] = 0;
    cout << ans + solve(mask) << '\n';
}