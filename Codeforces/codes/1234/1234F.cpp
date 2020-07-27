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
#define MAXC 1000005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %
const int m = 20, M = 1<<20;
string s;
int n, occ[m+1], v[MAXC], dp[M+1], cntBit[M+1];
bool there[M+1];

int solve(int x){
    if(dp[x]!=-1){
        return dp[x];
    }
    if(there[x]){
        return dp[x] = cntBit[x];
    }
    FOR(i, m){
        if(x&1<<i){
            dp[x] = max(dp[x], solve(x-(1<<i)));
        }
    }
    return dp[x];
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    n = s.length();
    FOR(i, n){
        v[i] = s[i]-'a';
    }
    int st = 0, en = 0, ans = 0;
    there[0] = true;
    while(en < n){
        while(occ[v[en]]){
            occ[v[st++]]--;
        }
        for(int i=st; i<=en; i++){
            int mark = 0;
            for(int j=i;j<=en;j++){
                mark |= 1<<v[j];
                there[mark] = true;
            }
        }
        occ[v[en++]]=1;
    }
    for(int i=1;i<=M;i++){
        cntBit[i] = 1 + cntBit[(i-1)&i];
        dp[i-1] = -1;
    }
    for(int i=0;i < M;i++){
        if(there[i]){
            ans = max(ans, cntBit[i] + solve(M-1-i));
        }
    }
    cout << ans << "\n";
}